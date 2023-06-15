
import sys,os
import imas
from imas import imasdef
import numpy as np
import matplotlib as mpl 
import matplotlib.pyplot as plt

import argparse
import xml.etree.ElementTree as ET

# importing the actors we want to run
import dinaimas21.wrapper as dinaimas21
import dina_green.wrapper as dina_green

import kmc.wrapper as kmc

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
                                       idslist['wall'],
                                       idslist['core_profiles'],
                                       idslist['core_sources'],
                                       idslist['transport_solver_numerics'],
                                       idslist['pulse_schedule'],
                                       arr_volt)
  # output of the actor is a tuple in Python
  
  idslist['equilibrium'] = output[0]
  idslist['magnetics'] = output[1]
  idslist['pf_active'] = output[2]
  idslist['pf_passive'] = output[3]
  idslist['core_profiles'] = output[4]
  idslist['core_sources'] = output[5]
  idslist['core_transport'] = output[6]
  idslist['summary'] = output[7]
  
  arr_curr = output[8]
  
  return arr_curr
  
  
  
def KMC(idslist, arr_curr):
  
  output = kmc.kmc_actor(idslist['pulse_schedule'],
                                       idslist['pulse_schedule_term'],
                                       idslist['equilibrium'],
                                       idslist['pf_active'],
                                       arr_curr)
  
  idslist['pf_active'] = output[0]
  arr_volt = output[1]
  
  return arr_volt



def GREEN(idslist):
  
  output = dina_green.dina_green_actor(idslist['pf_active'],
                                       idslist['pf_passive'],
                                       idslist['magnetics'])
  
  idslist['em_coupling'] = output[0]
  idslist['equilibrium'] = output[1]



def SOLPSZ(idslist):

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



class DINA_Workflow:
  def __init__(self, IMAS_PulseSchedule, IMAS_InputStart, IMAS_Output):
    
    # imas.DBEntry object containing input data to initialize the workflow
    self.IMAS_InputStart = IMAS_InputStart
    
    self.IMAS_PulseSchedule = IMAS_PulseSchedule
    
    # imas.DBEntry object to put output data in
    self.IMAS_Output = IMAS_Output
    
    # imas.DBEntry object containing prescribed transport profiles
    # Applied only when Time > self.Time_ExternalTranspStarts
    # If a valid object: the transport profiles are read from the object
    # If None: the transport is simulated in the workflow
    self.IMAS_Transp = None
    
    # Mode of interpolation for initialization data reading
    # imasdef.CLOSEST_INTERP == 1
    # imasdef.LINEAR_INTERP == 3
    #self.InterpMode = imasdef.LINEAR_INTERP # may cause a crash!
    self.InterpStart = imasdef.CLOSEST_INTERP
    
    # Mode of interpolation for prescribed transport reading
    #self.InterpMode = imasdef.LINEAR_INTERP # may cause a crash!
    self.InterpTransp = imasdef.CLOSEST_INTERP
    
    # Magnetic controller used in the simulation
    # One of directory names in src/controllers/
    self.MagneticController = "kmc"
    
    # Decimation used to put IDS's in the database
    # A full set of IDS's is saved only at each Decimation-th step
    # Other steps only pf_active and summary are saved
    self.Decimation = 1
    
    # Key for using ASTRA density transport model
    # Applied only when Time > self.Time_ExternalTranspStarts and self.IMAS_Transp is None
    # True: ASTRA density transport actor with internal density control
    # False: Transport module extracted from DINA with explicit puffing and pellet control
    self.USE_ASTRA = False
    
    # Time (s) after which DINA actor receives transport profiles (Prescribed, ASTRA, etc.) instead of calculating internally
    # Should correspond to tt_dina setting in the DINA actor
    self.Time_ExternalTranspStarts = 4.0e4
    
    # Starting time of the scenario
    # Initialization of the state uses data from IMAS_Input
    self.Time_Start = 0.0
    
    # Maximum time of the scenario
    self.Time_Stop = 1000.0
    
    self.idslist = {}


  def Run(self):
  
    #controllername = self.MagneticController
    #exec("import " + controllername + ".wrapper as " + controllername)
    #dinacontr = eval(controllername + "." + controllername + "_actor")
  
    idslist = {}
    
    # Reading initial IDS's
    self.IMAS_InputStart.open()
    
    Restart = self.Time_Start > 0.0
    
    
    
    if (Restart == True):
      interp = self.InterpStart
      TimeGet = self.Time_Start
      print('Restart at t = ' + str(TimeGet))
      idslist['equilibrium'] = self.IMAS_InputStart.get_slice('equilibrium', TimeGet, interp)
      idslist['em_coupling'] = self.IMAS_InputStart.get_slice('em_coupling', TimeGet, interp)
      idslist['magnetics'] = self.IMAS_InputStart.get_slice('magnetics', TimeGet, interp)
      idslist['pf_active'] = self.IMAS_InputStart.get_slice('pf_active', TimeGet, interp)
      idslist['pf_passive'] = self.IMAS_InputStart.get_slice('pf_passive', TimeGet, interp)
      idslist['core_profiles'] = self.IMAS_InputStart.get_slice('core_profiles', TimeGet, interp)
      idslist['core_sources'] = self.IMAS_InputStart.get_slice('core_sources', TimeGet, interp)
      idslist['transport_solver_numerics'] = self.IMAS_InputStart.get_slice('transport_solver_numerics', TimeGet, interp)
    else:
      print('Start from t = 0') 
      #idslist['equilibrium'] = self.IMAS_InputStart.get('equilibrium')
      idslist['magnetics'] = self.IMAS_InputStart.get('magnetics')
      idslist['pf_active'] = self.IMAS_InputStart.get('pf_active')
      idslist['pf_passive'] = self.IMAS_InputStart.get('pf_passive')
      idslist['core_profiles'] = self.IMAS_InputStart.get('core_profiles')
      idslist['core_sources'] = self.IMAS_InputStart.get('core_sources')
      idslist['transport_solver_numerics'] = self.IMAS_InputStart.get('transport_solver_numerics')
      
      GREEN(idslist)
    
    
    idslist['wall'] = self.IMAS_InputStart.get('wall')
    idslist['dataset_description'] = self.IMAS_InputStart.get('dataset_description')
    
    self.IMAS_InputStart.close()
    
    
    self.IMAS_PulseSchedule.open()
    idslist['pulse_schedule'] = self.IMAS_PulseSchedule.get('pulse_schedule')
    idslist['pulse_schedule_term'] = self.IMAS_PulseSchedule.get('pulse_schedule', occurrence = 1)
    self.IMAS_PulseSchedule.close()
    
    
    #print('Time_Start = ' + str(idslist['equilibrium'].time_slice[0].time), flush=True)
    
    # Preparing of an IMAS entry for the simulation output
    self.IMAS_Output.create()
    
    
    self.IMAS_Output.put(idslist["dataset_description"])
    self.IMAS_Output.put(idslist["pulse_schedule"])
    self.IMAS_Output.put(idslist["pulse_schedule_term"], occurrence = 1)
    self.IMAS_Output.put(idslist['em_coupling'])
    self.IMAS_Output.put(idslist['wall'])
    
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
      
      # Magnetic controller
      arr_volt = KMC(idslist, arr_curr)
      #arr_volt = dinacontr(arr_curr)
      #arr_volt = dinacontr21_1a.dinacontr21_1a_actor(arr_curr)
      
      
      ip = idslist['summary'].global_quantities.ip.value[0]
      time = idslist['summary'].time[0]
      timearr.append(time)
      print('DINA loop = ' + str(iloop), flush=True)
      
      # External transport
      if (time >= self.Time_ExternalTranspStarts):
        
        if (self.IMAS_Transp != None):
          
          TimeGet = time
          
          self.IMAS_Transp.open()
          idslist['core_profiles'] = self.IMAS_Transp.get_slice('core_profiles', TimeGet, self.InterpTransp)
          idslist['core_sources'] = self.IMAS_Transp.get_slice('core_sources', TimeGet, self.InterpTransp)
          self.IMAS_Transp.close()
          
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
      SOLPSZ(idslist)
    
    
      #n1 = len(core_profiles.profiles_1d[0].grid.rho_tor_norm)
      #print('n1 = ' + str(n1))
    
      #te0 = core_profiles.profiles_1d[0].electrons.temperature[0:n1-1]
      #tq0 = core_profiles.profiles_1d[0].t_i_average[0:n1-1]
      
      
      # Put this slice to the database 
      if (iloop%self.Decimation == 0 or iloop == iloop_start):
        self.IMAS_Output.put_slice(idslist['equilibrium'])
        self.IMAS_Output.put_slice(idslist['magnetics'])
        self.IMAS_Output.put_slice(idslist['pf_active'])
        self.IMAS_Output.put_slice(idslist['pf_passive'])
        self.IMAS_Output.put_slice(idslist['core_profiles'])
        self.IMAS_Output.put_slice(idslist['core_sources'])
        self.IMAS_Output.put_slice(idslist['core_transport'])
        self.IMAS_Output.put_slice(idslist['summary'])
      else:
        self.IMAS_Output.put_slice(idslist['pf_active'])
        self.IMAS_Output.put_slice(idslist['summary'])
      
      
      
      print('Workflow step=' + str(iloop) + '; time=' + str(time) + ' s; Ipl=' + str(ip) + ' A', flush=True)
      
      # Condition for stopping the simulation
      tpfa = 0.
      for coil in idslist['pf_active'].coil:
        tpfa = tpfa + abs(coil.current.data[0])
  
      if ((tpfa < 1.e3 and abs(ip) < 1.e3) or time > self.Time_Stop):
        print('Workflow stop condition is met', flush=True)
        break
    
      iloop = iloop + 1
    
    
    self.IMAS_Output.close()
    
    print('Finished successfully after ' + str(iloop) + ' steps')
    #print(timearr)
    #print(dina_tuple)
    #print(dir(pf_active))


def start(config):
  
  if (type(config) == str):
    tree = ET.parse(config)
  root = tree.getroot()
  
  user_default = os.getenv('USER')
  
  
  input_start = root.find('input_start')
  usernode = input_start.find('user')
  if (usernode != None):
    username = usernode.text
  else:
    username = None
  if (username == None or username == ""):
    username = user_default
  database = input_start.find('database').text
  pulse = int(input_start.find('pulse').text)
  run = int(input_start.find('run').text)
  IMAS_InputStart = imas.DBEntry(imasdef.MDSPLUS_BACKEND, database, pulse, run, username, data_version = '3')
  
  
  input_psch = root.find('pulse_schedule')
  usernode = input_psch.find('user')
  if (usernode != None):
    username = usernode.text
  else:
    username = None
  if (username == None or username == ""):
    username = user_default
  database = input_psch.find('database').text
  pulse = int(input_psch.find('pulse').text)
  run = int(input_psch.find('run').text)
  IMAS_PulseSchedule = imas.DBEntry(imasdef.MDSPLUS_BACKEND, database, pulse, run, username, data_version = '3')
  
  
  output = root.find('output')
  database = output.find('database').text
  pulse = int(output.find('pulse').text)
  run = int(output.find('run').text)
  IMAS_Output = imas.DBEntry(imasdef.MDSPLUS_BACKEND, database, pulse, run, user_default, data_version = '3')
  
  
  Workflow = DINA_Workflow(IMAS_PulseSchedule, IMAS_InputStart, IMAS_Output)
  Workflow.InterpStart = int(input_start.find('interp_mode').text)
  Workflow.Time_Start = float(input_start.find('time_start').text)
  Workflow.Time_Stop = float(root.find('time_stop').text)
  Workflow.Time_ExternalTranspStarts = float(root.find('time_ext').text)
  Workflow.MagneticController = root.find('controller').text
  Workflow.Decimation = int(output.find('decimation').text)
  Workflow.USE_ASTRA = bool(root.find('use_astra').text)
  
  
  input_transp = root.find('input_transp')
  if (input_transp != None):
    usernode = input_transp.find('user')
    if (usernode != None):
      username = usernode.text
    else:
      username = None
    if (username == None or username == ""):
      username = user_default
    database = input_transp.find('database').text
    pulse = int(input_transp.find('pulse').text)
    run = int(input_transp.find('run').text)
    
    if (database != None):
      Workflow.IMAS_Transp = imas.DBEntry(imasdef.MDSPLUS_BACKEND, database, pulse, run, username, data_version = '3')
      Workflow.InterpTransp = int(input_transp.find('interp_mode').text)
  
  
  Workflow.Run()


def main():
  
  parser = argparse.ArgumentParser(description='----DINA Workflow')
  parser.add_argument('-c','--config',help='Path to a configuration XML', required=False, type=str)
  args = vars(parser.parse_args())
  
  if args['config'] != None:
      config = args['config']
  else:
      config = 'wfconfig.xml'
  
  start(config)


if __name__ == '__main__':  # If direct run, not import
  main()
