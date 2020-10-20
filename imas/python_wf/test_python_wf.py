# should convert this script in order to use imas.DBEntry instead of old Python API, so writing of the results from the actor is more natural
import imas
from imas import imasdef
import numpy as np


# importing the actors we want to run
import dinaimas21.wrapper as dinaimas21
import dinacontr21.wrapper as dinacontr21
import dinatransp_bootcond.wrapper as dinatransp_bootcond
import dinatransp_curdrive.wrapper as dinatransp_curdrive
import dinatransp_density.wrapper as dinatransp_density
import dinatransp_energy.wrapper as dinatransp_energy
import dinatransp_heatsrc.wrapper as dinatransp_heatsrc
import solps_imas.wrapper as solps


#print(dir(imasdef))


pulse_in = 170
run_in = 1

pulse_out = 170
run_out = 27


# importing IDS data, equivalent to UALInit
imas_entry_init = imas.DBEntry(imasdef.MDSPLUS_BACKEND, 'test', pulse_in, run_in, user_name = 'dubrovm', data_version = '3')
imas_entry_init.open()


#Alternative technique of getting
#equilibrium = imas.equilibrium()
#equilibrium.get(db_entry = imas_entry_init, occurrence = 0)
equilibrium = imas_entry_init.get('equilibrium', occurrence = 0)

em_coupling = imas_entry_init.get('em_coupling')
pf_active = imas_entry_init.get('pf_active')
pf_passive = imas_entry_init.get('pf_passive')
core_profiles = imas_entry_init.get('core_profiles')
core_sources = imas_entry_init.get('core_sources')
core_transport = imas_entry_init.get('core_transport')
transport_solver_numerics = imas_entry_init.get('transport_solver_numerics')
pulse_schedule = imas_entry_init.get('pulse_schedule')
summary = imas_entry_init.get('summary')


imas_entry_init.close()

imas_entry_result = imas.DBEntry(imasdef.MDSPLUS_BACKEND, 'test', pulse_out, run_out, user_name = 'dubrovm', data_version = '3')
imas_entry_result.create()


arr_volt = np.float64(range(501))

iloop_start = 0
iloop = iloop_start
while True:
   
  # executing the actor
  dina_tuple = dinaimas21.dinaimas21_actor(em_coupling,equilibrium,pf_active,pf_passive,core_profiles,core_sources,transport_solver_numerics,pulse_schedule,arr_volt)
  # output of the actor is a tuple in Python
  
  print('DINA loop = ' + str(iloop) + ', output tuple length is ' + str(len(dina_tuple)))

  em_coupling = dina_tuple[0]
  equilibrium = dina_tuple[1]
  magnetics = dina_tuple[2]
  pf_active = dina_tuple[3]
  pf_passive = dina_tuple[4]
  core_profiles = dina_tuple[5]
  core_sources = dina_tuple[6]
  core_transport = dina_tuple[7]
  summary = dina_tuple[8]

  ip = summary.global_quantities.ip.value[0]
  time = summary.time[0]

  arr_curr = dina_tuple[9]  
  contr_tuple = dinacontr21.dinacontr21_actor(arr_curr)
  arr_volt = contr_tuple
  

  #n1 = len(core_profiles.profiles_1d[0].grid.rho_tor_norm)
  #print('n1 = ' + str(n1))

  #te0 = core_profiles.profiles_1d[0].electrons.temperature[0:n1-1]
  #tq0 = core_profiles.profiles_1d[0].t_i_average[0:n1-1]
  
  
  
  # Put this slice to the database
  imas_entry_result.put_slice(em_coupling)
  imas_entry_result.put_slice(equilibrium)
  imas_entry_result.put_slice(magnetics)
  imas_entry_result.put_slice(pf_active)
  imas_entry_result.put_slice(pf_passive)
  imas_entry_result.put_slice(core_profiles) 
  imas_entry_result.put_slice(core_sources)
  imas_entry_result.put_slice(core_transport)
  imas_entry_result.put_slice(summary)   
  
  
  
  print('Workflow step=' + str(iloop) + '; time=' + str(time) + ' s; Ipl=' + str(ip) + ' A')
  
  # Condition for end the simulation
  if (time > 20.0 and ip < 1.e3 or iloop > 5):
    break
    
  iloop = iloop + 1


imas_entry_result.close()

print('Finished successfully')
#print(dina_tuple)



print(dir(pf_active))

