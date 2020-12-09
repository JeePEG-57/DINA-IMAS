# should convert this script in order to use imas.DBEntry instead of old Python API, so writing of the results from the actor is more natural
import imas
from imas import imasdef
import numpy as np
import inspect

import matplotlib as mpl 
import matplotlib.pyplot as plt


# importing the actors we want to run
import dinaimas21.wrapper as dinaimas21
import dinacontr21.wrapper as dinacontr21
import dinatransp_bootcond.wrapper as dinatransp_bootcond
import dinatransp_curdrive.wrapper as dinatransp_curdrive
import dinatransp_density.wrapper as dinatransp_density
import dinatransp_energy.wrapper as dinatransp_energy
import dinatransp_heatsrc.wrapper as dinatransp_heatsrc
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
                                       idslist['pf_active'],
                                       idslist['pf_passive'],
                                       idslist['core_profiles'],
                                       idslist['core_sources'],
                                       idslist['transport_solver_numerics'],
                                       idslist['pulse_schedule'],
				       idslist['summary'],
                                       arr_volt)
  # output of the actor is a tuple in Python
  
  idslist['em_coupling'] = output[0]
  idslist['equilibrium'] = output[1]
  #idslist['magnetics'] = output[2]
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
                                                       sources,
                                                       idslist['transport_solver_numerics'])
                                                               
  idslist['core_profiles'] = output
  


def BOOTCOND(idslist):
  
  output = dinatransp_bootcond.dinatransp_bootcond_actor(idslist['equilibrium'],
                                                         idslist['core_profiles'])
  
  idslist['core_profiles'] = output
  
  
  
def CURDRIVE(idslist):
  
  output = dinatransp_curdrive.dinatransp_curdrive_actor(idslist['equilibrium'],
                                                        idslist['core_profiles'])
  
  idslist['core_profiles'] = output



idslist = {}

user_name='kims12'

pulse_in = 170
run_in = 1

pulse_out = 170
run_out = 400

# Time since external transport actors fire
timeExternalTransport = 1.52


# Reading initial IDS's
imas_entry_init = imas.DBEntry(imasdef.MDSPLUS_BACKEND, 'test', pulse_in, run_in, user_name, data_version = '3')
imas_entry_init.open()


#Alternative technique of getting
#equilibrium = imas.equilibrium()
#equilibrium.get(db_entry = imas_entry_init, occurrence = 0)
idslist['equilibrium'] = imas_entry_init.get('equilibrium', occurrence = 0)

idslist['em_coupling'] = imas_entry_init.get('em_coupling')
idslist['pf_active'] = imas_entry_init.get('pf_active')
idslist['pf_passive'] = imas_entry_init.get('pf_passive')
idslist['core_profiles'] = imas_entry_init.get('core_profiles')
idslist['core_sources'] = imas_entry_init.get('core_sources')
idslist['core_transport'] = imas_entry_init.get('core_transport')
idslist['transport_solver_numerics'] = imas_entry_init.get('transport_solver_numerics')
idslist['pulse_schedule'] = imas_entry_init.get('pulse_schedule')
idslist['summary'] = imas_entry_init.get('summary')
#idslist['dataset_description'] = imas_entry_init.get('dataset_description')

imas_entry_init.close()


# Preparing of an IMAS entry for the simulation output
imas_entry_result = imas.DBEntry(imasdef.MDSPLUS_BACKEND, 'test', pulse_out, run_out, user_name, data_version = '3')
imas_entry_result.create()


# Allocation for initial voltages of the magnetic control
arr_volt = np.float64(range(501))


# The main loop
iloop_start = 0
iloop = iloop_start
timearr = []
while True:
   
  # DINA 
  arr_curr = DINA(idslist, arr_volt)
  

  ip = idslist['summary'].global_quantities.ip.value[0]
  time = idslist['summary'].time[0]
  timearr.append(time)
  print('DINA loop = ' + str(iloop))

  # External transport
  if time >= timeExternalTransport:
    
    HEATSRC(idslist)
    ENERGY(idslist)
    
    # Density control and sources distribution    
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
  arr_volt = dinacontr21.dinacontr21_actor(arr_curr)
  


  #n1 = len(core_profiles.profiles_1d[0].grid.rho_tor_norm)
  #print('n1 = ' + str(n1))

  #te0 = core_profiles.profiles_1d[0].electrons.temperature[0:n1-1]
  #tq0 = core_profiles.profiles_1d[0].t_i_average[0:n1-1]
  
  
  
  # Put this slice to the database
  #for key in idslist:
  #  imas_entry_result.put_slice(idslist[key])
  
  #imas_entry_result.put_slice(idslist['em_coupling'])
  imas_entry_result.put_slice(idslist['equilibrium'])
  #imas_entry_result.put_slice(idslist['magnetics'])
  imas_entry_result.put_slice(idslist['pf_active'])
  imas_entry_result.put_slice(idslist['pf_passive'])
  #imas_entry_result.put_slice(idslist['core_profiles'])
  #imas_entry_result.put_slice(idslist['core_sources'])
  #imas_entry_result.put_slice(idslist['core_transport'])
  imas_entry_result.put_slice(idslist['summary'])
  
  
  
  print('Workflow step=' + str(iloop) + '; time=' + str(time) + ' s; Ipl=' + str(ip) + ' A', flush=True)
  
  # Condition for stopping the simulation
  if (time > 20.0 and ip < 1.e3 or time > 2.0):
    break
    
  iloop = iloop + 1


imas_entry_result.close()

print('Finished successfully after ' + str(iloop) + ' steps')
print(timearr)
#print(dina_tuple)
#print(dir(pf_active))


# Plasma current plot
summary = idslist['summary']
t1 = summary.time
ipl1 = summary.global_quantities.ip.value

fig_ipl = plt.figure()
plt.plot(t1, ipl1)
plt.xlabel('time, s')
plt.ylabel('I_pl, A')
plt.title('Plasma current')
plt.grid(True)

plt.show()
