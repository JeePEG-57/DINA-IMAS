# should convert this script in order to use imas.DBEntry instead of old Python API, so writing of the results from the actor is more natural
import imas

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


#dbo = imas.ids(999,1)
#dbo.create_env('dubrovm','test','3')
#dbo.em_coupling.get()
#dbo.equilibrium.get()
#dbo.pf_active.get()
#dbo.pf_passive.get()
#dbo.core_profiles.get()
#dbo.core_sources.get()
#dbo.transport_solver_numerics.get()
#dbo.pulse_schedule.get()
#dbo.summary.get()
#dbo.magnetics.get()

# importing the actor we want to run
import dinaimas21.wrapper as dinaimas21


arr_in1 = range(501)
arr_out1 = range(501)

# executing the actor
#result_tuple = dinaimas21.dinaimas21_actor(db.em_coupling,db.equilibrium,db.pf_active,db.pf_passive,db.core_profiles,db.core_sources,db.transport_solver_numerics,db.pulse_schedule,db.summary,arr_in1)
result_tuple = dinaimas21.dinaimas21_actor(db.em_coupling,db.equilibrium,db.pf_active,db.pf_passive,db.core_profiles,db.core_sources,db.transport_solver_numerics,db.pulse_schedule,arr_in1)



# output of the actor is a tuple in Python
print('Success, result tuple is:')
print(result_tuple)

