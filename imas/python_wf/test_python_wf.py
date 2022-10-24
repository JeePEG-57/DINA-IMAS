
import os
import sys

import imas
from imas import imasdef
import numpy as np
import inspect

import matplotlib as mpl 
import matplotlib.pyplot as plt


# importing the actors we want to run
import dinaimas21.wrapper as dinaimas21

import dinatransp_bootcond.wrapper as dinatransp_bootcond
import dinatransp_curdrive.wrapper as dinatransp_curdrive
import dinatransp_density.wrapper as dinatransp_density
import dinatransp_energy.wrapper as dinatransp_energy
import dinatransp_heatsrc.wrapper as dinatransp_heatsrc

import astra_transp_density.wrapper as astratransp_density
import astra_sources_pellet.wrapper as astra_sources_pellet
import astra_sources_valve.wrapper as astra_sources_valve
import density_control_pellet.wrapper as density_control_pellet
import density_control_valve.wrapper as density_control_valve

import solps_imas.wrapper as solps_imas


#print(dir(imasdef))
#print(dir(dinaimas21))
#print(dinaimas21.dinaimas21_actor.__doc__)
#sig = inspect.signature(dinaimas21.dinaimas21_actor)
# print(sig.parameters) # Is filled
# print(sig.return_annotation) # Is empty



def DINA(idslist, arr_volt):

  output = dinaimas21.dinaimas21_actor(idslist['em_coupling'],
                                       idslist['equilibrium'],
                                       idslist['magnetics'],
                                       idslist['pf_active'],
                                       idslist['pf_passive'],
                                       idslist['core_profiles'],
                                       idslist['core_sources'],
                                       idslist['transport_solver_numerics'],
                                       idslist['pulse_schedule'],
                                       arr_volt)
  # output of the actor is a tuple in Python
  
  idslist['em_coupling'] = output[0]
  idslist['equilibrium'] = output[1]
  idslist['magnetics'] = output[2]
  idslist['pf_active'] = output[3]
  idslist['pf_passive'] = output[4]
  idslist['core_profiles'] = output[5]
  idslist['core_sources'] = output[6]
  idslist['core_transport'] = output[7]
  idslist['summary'] = output[8]
  
  arr_curr = output[9]
  
  return arr_curr
  


def SOLPS(idslist):

  output = solps_imas.solps_imas_actor(idslist['equilibrium'],
                             idslist['core_transport'])
  
  idslist['transport_solver_numerics'] = output



def HEATSRC(idslist):
  
  output = dinatransp_heatsrc.dinatransp_heatsrc_actor(idslist['equilibrium'],
                                                       idslist['core_sources'])

  idslist['core_sources'] = output
  
  

def ENERGY(idslist):
  
  output = dinatransp_energy.dinatransp_energy_actor(idslist['equilibrium'],
                                                     idslist['core_profiles'],
                                                     idslist['core_sources'],
                                                     idslist['transport_solver_numerics'])
  
  idslist['core_profiles'] = output[0]
  idslist['core_sources'] = output[1]



def ASTRASRC_PELLET(idslist, cmd):
  
  output = astra_sources_pellet.astra_sources_pellet_actor(idslist['equilibrium'],
                                                           idslist['core_profiles'],
                                                           cmd)
  
  sources = output
  return sources



def ASTRASRC_VALVE(idslist, cmd):
  
  output = astra_sources_valve.astra_sources_valve_actor(idslist['equilibrium'],
                                                           idslist['core_profiles'],
                                                           cmd)
  
  sources = output
  return sources



def DENSITY(idslist, sources):
  
  #sources = idslist['core_sources']
  output = dinatransp_density.dinatransp_density_actor(idslist['equilibrium'],
                                                       idslist['core_profiles'],
                                                       idslist['summary'],
                                                       sources,
                                                       idslist['transport_solver_numerics'])
                                                               
  idslist['core_profiles'] = output[0]
  idslist['summary'] = output[1]


def BOOTCOND(idslist):
  
  output = dinatransp_bootcond.dinatransp_bootcond_actor(idslist['equilibrium'],
                                                         idslist['core_profiles'])
  
  idslist['core_profiles'] = output
  
  
  
def CURDRIVE(idslist):
  
  output = dinatransp_curdrive.dinatransp_curdrive_actor(idslist['equilibrium'],
                                                        idslist['core_profiles'])
  
  idslist['core_profiles'] = output



def ASTRA_DENSITY(idslist):
  
  output = dinatransp_density.dinatransp_density_actor(idslist['equilibrium'],
                                                       idslist['core_profiles'],                                                                                             
                                                       idslist['transport_solver_numerics'])
  
  idslist['core_profiles'] = output


class IMASDB_Entry:
  def __init__(self, shot, run, database, username):
    self.shot = shot
    self.run = run
    self.database = database
    self.username = username
    
    
class DINA_Workflow:
  def __init__(self, IMAS_Input, IMAS_Output):
    
    # IMASDB_Entry structure with IMAS coordinates to get input data
    self.IMAS_Input = IMAS_Input
    # IMASDB_Entry structure with IMAS coordinates to put output data
    self.IMAS_Output = IMAS_Output
    
    # Magnetic controller used in the simulation
    # One of directory names in src/controllers/
    self.MagneticController = "kmc"
    
    # Decimation used to put IDS's in the database
    # Each Decimation-th step will be stored
    self.Decimation = 10
    
    # Key for using prescribed transport profiles
    # True: The transport profiles are read from the IMAS_Input
    # False: The transport is simulated in the workflow
    self.PRESCRIBED_TRANSPORT = False
    
    # Key for using ASTRA density transport model
    # True: ASTRA density transport actor with internal density control
    # False: Transport module extracted from DINA with explicit puffing and pellet control
    self.USE_ASTRA = False
    
    # Time (s) after which DINA actor receives transport profiles (Prescribed, ASTRA, etc.) instead of calculating internally
    self.Time_ExternalTranspStarts = 4.0e4
    
    # Starting time of the scenario
    # Initialisation of the state uses data from IMAS_Input
    self.Time_Start = 0.0
    
    # Maximum time of the scenario
    self.Time_Stop = 1000.0
    
    self.idslist = {}


  def Run(self):
  
    controllername = self.MagneticController
    exec("import " + controllername + ".wrapper as " + controllername)
    dinacontr = eval(controllername + "." + controllername + "_actor")
  
    idslist = {}
    
    # Reading initial IDS's
    user_in = self.IMAS_Input.username
    db_in = self.IMAS_Input.database
    shot_in = self.IMAS_Input.shot
    run_in = self.IMAS_Input.run
    imas_entry_init = imas.DBEntry(imasdef.MDSPLUS_BACKEND, db_in, shot_in, run_in, user_in, data_version = '3')
    imas_entry_init.open()
    
    
    Restart = self.Time_Start > 0.0
    
    
    if (Restart == True):
      interp = imasdef.CLOSEST_INTERP
      TimeGet = self.Time_Start
      print('Restart at t = ' + str(TimeGet))
      idslist['equilibrium'] = imas_entry_init.get_slice('equilibrium', TimeGet, interp)
      idslist['em_coupling'] = imas_entry_init.get_slice('em_coupling', TimeGet, interp)
      idslist['magnetics'] = imas_entry_init.get_slice('magnetics', TimeGet, interp)
      idslist['pf_active'] = imas_entry_init.get_slice('pf_active', TimeGet, interp)
      idslist['pf_passive'] = imas_entry_init.get_slice('pf_passive', TimeGet, interp)
      idslist['core_profiles'] = imas_entry_init.get_slice('core_profiles', TimeGet, interp)
      idslist['core_sources'] = imas_entry_init.get_slice('core_sources', TimeGet, interp)
      idslist['transport_solver_numerics'] = imas_entry_init.get_slice('transport_solver_numerics', TimeGet, interp)
    else:
      print('Start from t = 0')
      idslist['equilibrium'] = imas_entry_init.get('equilibrium', occurrence = 0)
      idslist['em_coupling'] = imas_entry_init.get('em_coupling')
      idslist['magnetics'] = imas_entry_init.get('magnetics')
      idslist['pf_active'] = imas_entry_init.get('pf_active')
      idslist['pf_passive'] = imas_entry_init.get('pf_passive')
      idslist['core_profiles'] = imas_entry_init.get('core_profiles')
      idslist['core_sources'] = imas_entry_init.get('core_sources')
      idslist['transport_solver_numerics'] = imas_entry_init.get('transport_solver_numerics')
      
    
    idslist['wall'] = imas_entry_init.get('wall')
    idslist['dataset_description'] = imas_entry_init.get('dataset_description')
    idslist['pulse_schedule'] = imas_entry_init.get('pulse_schedule')
    #idslist['summary'] = imas_entry_init.get('summary')
    
    imas_entry_init.close()
    
    #print('Time_Start = ' + str(idslist['equilibrium'].time_slice[0].time), flush=True)
    
    # Preparing of an IMAS entry for the simulation output
    user_out = self.IMAS_Output.username
    db_out = self.IMAS_Output.database
    shot_out = self.IMAS_Output.shot
    run_out = self.IMAS_Output.run
    
    imas_entry_result = imas.DBEntry(imasdef.MDSPLUS_BACKEND, db_out, shot_out, run_out, user_out, data_version = '3')
    imas_entry_result.create()
    
    
    imas_entry_result.put(idslist["dataset_description"])
    imas_entry_result.put(idslist["pulse_schedule"])
    
    
    # Allocation for initial voltages of the magnetic control
    arr_volt = np.float64(range(501))
    
    
    # The main loop
    iloop_start = 0
    iloop = iloop_start
    timearr = []
    while True:
      
      self.idslist = idslist
      
      # DINA 
      arr_curr = DINA(idslist, arr_volt)
      
    
      ip = idslist['summary'].global_quantities.ip.value[0]
      time = idslist['summary'].time[0]
      timearr.append(time)
      print('DINA loop = ' + str(iloop))
      
      # External transport
      if (time >= self.Time_ExternalTranspStarts):
        
        if (self.PRESCRIBED_TRANSPORT == True):
          
          interp = imasdef.LINEAR_INTERP
          TimeGet = time
          
          user_in = self.IMAS_Input.username
          db_in = self.IMAS_Input.database
          shot_in = self.IMAS_Input.shot
          run_in = self.IMAS_Input.run
          imas_entry_init = imas.DBEntry(imasdef.MDSPLUS_BACKEND, db_in, shot_in, run_in, user_in, data_version = '3')
          imas_entry_init.open()
          idslist['core_profiles'] = imas_entry_init.get_slice('core_profiles', TimeGet, interp)
          idslist['core_sources'] = imas_entry_init.get_slice('core_sources', TimeGet, interp)
          imas_entry_init.close()
          
        else:
        
          HEATSRC(idslist)
          ENERGY(idslist)
          
          if self.USE_ASTRA:
            ASTRA_DENSITY(idslist)
          else:
            # Density controllers
            cmd_pellet = density_control_pellet.density_control_pellet_actor(idslist['summary'])
            cmd_valve = density_control_valve.density_control_valve_actor(idslist['summary'])
                
            # Density sources distribution
            densitysrc_pellet = ASTRASRC_PELLET(idslist, cmd_pellet)
            densitysrc_valve = ASTRASRC_VALVE(idslist, cmd_valve)
            
            densitysrc = densitysrc_pellet + densitysrc_valve
                
            DENSITY(idslist, densitysrc)
          
      
          
          BOOTCOND(idslist)
          CURDRIVE(idslist)
        
          # Boundary conditions
          SOLPS(idslist)
    
      # Magnetic controller
      arr_volt = dinacontr(arr_curr)
      #arr_volt = dinacontr21_1a.dinacontr21_1a_actor(arr_curr)
    
      #n1 = len(core_profiles.profiles_1d[0].grid.rho_tor_norm)
      #print('n1 = ' + str(n1))
    
      #te0 = core_profiles.profiles_1d[0].electrons.temperature[0:n1-1]
      #tq0 = core_profiles.profiles_1d[0].t_i_average[0:n1-1]
      
      
      # Put this slice to the database 
      if (iloop%self.Decimation == 0 or iloop == iloop_start):
        #for key in idslist:
        #  imas_entry_result.put_slice(idslist[key])
        imas_entry_result.put_slice(idslist['em_coupling'])
        imas_entry_result.put_slice(idslist['equilibrium'])
        imas_entry_result.put_slice(idslist['magnetics'])
        imas_entry_result.put_slice(idslist['pf_active'])
        imas_entry_result.put_slice(idslist['pf_passive'])
        imas_entry_result.put_slice(idslist['core_profiles'])
        imas_entry_result.put_slice(idslist['core_sources'])
        imas_entry_result.put_slice(idslist['core_transport'])
        imas_entry_result.put_slice(idslist['summary'])
        imas_entry_result.put_slice(idslist['wall'])
      
      
      
      print('Workflow step=' + str(iloop) + '; time=' + str(time) + ' s; Ipl=' + str(ip) + ' A', flush=True)
      
      # Condition for stopping the simulation
      tpfa = 0.
      for coil in idslist['pf_active'].coil:
        tpfa = tpfa + abs(coil.current.data[0])
  
      if ((tpfa < 1.e3 and abs(ip) < 1.e3) or time > self.Time_Stop):
        print('Workflow stop condition is met', flush=True)
        break
    
      iloop = iloop + 1
    
    
    imas_entry_result.close()
    
    print('Finished successfully after ' + str(iloop) + ' steps')
    #print(timearr)
    #print(dina_tuple)
    #print(dir(pf_active))



def main(argv):
    
  user_name = os.getenv('USER')

  IMAS_Input = IMASDB_Entry(170, 1, "test", user_name) 
  IMAS_Output = IMASDB_Entry(170, 45, "test", user_name) 

  Workflow = DINA_Workflow(IMAS_Input, IMAS_Output)
  Workflow.Time_Start = 0.0
  Workflow.Time_ExternalTranspStarts = 40000.0
  Workflow.PRESCRIBED_TRANSPORT = True
  
  Workflow.Run()

if __name__ == '__main__':  # If direct run, not import
  main(sys.argv[1:]) 
    
