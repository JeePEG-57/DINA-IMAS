# should convert this script in order to use imas.DBEntry instead of old Python API, so writing of the results from the actor is more natural
import imas
import numpy as np

# importing IDS data, equivalent to UALInit
db = imas.ids(170,1)
db.open_env('dubrovm','test','3')
db.em_coupling.get()
db.equilibrium.get()
db.pf_active.get()
db.pf_passive.get()
db.core_profiles.get()
db.core_sources.get()
db.transport_solver_numerics.get()
db.pulse_schedule.get()
db.summary.get()


# importing the actors we want to run
import dinaimas21.wrapper as dinaimas21
import dinacontr21.wrapper as dinacontr21



em_coupling = db.em_coupling
equilibrium = db.equilibrium
pf_active = db.pf_active
pf_passive = db.pf_passive
core_profiles = db.core_profiles
core_sources = db.core_sources
core_transport = db.core_transport
transport_solver_numerics = db.transport_solver_numerics
pulse_schedule = db.pulse_schedule
summary = db.summary
arr_volt = np.float64(range(501))


for i in range(10):
  # executing the actor
  dina_tuple = dinaimas21.dinaimas21_actor(em_coupling,equilibrium,pf_active,pf_passive,core_profiles,core_sources,transport_solver_numerics,pulse_schedule,arr_volt)
  # output of the actor is a tuple in Python
  
  print('DINA loop = ' + str(i) + ', output tuple length is ' + str(len(dina_tuple)))

  em_coupling = dina_tuple[0]
  equilibrium = dina_tuple[1]
  magnetics = dina_tuple[2]
  pf_active = dina_tuple[3]
  pf_passive = dina_tuple[4]
  core_profiles = dina_tuple[5]
  core_sources = dina_tuple[6]
  core_transport = dina_tuple[7]
  summary = dina_tuple[8]


  arr_curr = dina_tuple[9]  
  contr_tuple = dinacontr21.dinacontr21_actor(arr_curr)
  arr_volt = contr_tuple
  
  print('Control loop = ' + str(i))
  n1 = len(core_profiles.profiles_1d[0].grid.rho_tor_norm)
  print('n1 = ' + str(n1))

  #te0 = core_profiles.profiles_1d[0].electrons.temperature[0:n1-1]
  #tq0 = core_profiles.profiles_1d[0].t_i_average[0:n1-1]
  
  #core_profiles.putSlice()



print('Success, last dina tuple is:')
print(dina_tuple)

