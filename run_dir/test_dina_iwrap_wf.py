"""Testing IWrap overhead with 2000 <step_max>2000</step_max> in wfconfig.xml 
on AMD EPYC 7402 24-Core Processor (UL cluster)

The IWrap workflow actor tested is just outputing IDSs. Input IDSs are being read
from disk.

1. Fortran with (unmodified) ids_put_slice and idec=10 using
    time ../interface/test_dina wfconfig.xml > /dev/shm/dina.log 2>&1 &
    tail -f /dev/shm/dina.log | stdbuf -o0 grep iloop

real    28m47s
user    11m47s

2. Fortran as in 1. without ids_put_slice (commented out)

real    11m39.354s
user    11m24.083s
sys     0m2.137s

3. IWrapped Fortran with returning summary and pf_active each time step and the complete at idec=10
    time python test_dina_iwrap_wf.py  > /dev/shm/dina.log 2>&1 &
    tail -f /dev/shm/dina.log | stdbuf -o0 grep iloop

real    13m20.151s
user    13m3.251s
sys     0m3.273s

4. IWrapped  Fortran as in 3. with returning all IDSs at each time step
<decimation>1</decimation> in wfconfig.xml. Note that rebuild of the actor is
needed to get decimation impact. 

real    16m1.107s
user    15m42.810s
sys     0m2.925s

5. Python workflow with ids_put_slice commented out as in Fortran (2.) and with 
    if loop == 2000:  break at the end of while True: loop
 
    . use_actors.sh
    time python test_python_wf.py  > /dev/shm/dina.log 2>&1 &
    tail -f /dev/shm/dina.log | stdbuf -o0 grep "loop ="

real    23m10.938s
user    22m52.005s
sys     0m2.916s

6. Python workflow with ids_put_slice (unmodified)

real    76m31.742s
user    24m31.537s
sys     8m39.438s

7. IWrap workflow with memory backend for summary and pf_active 
step routine does idec loops and returns idec number of slices.

real    12m15.815s
user    11m58.820s
sys     0m2.589s

8. Iwrap workflow as 7. with added 10 input IDSs?

real    12m16.117s
user    11m59.082s
sys     0m2.705s


Comments:

We see that there is an Iwrap overhead of case 4. over case 3. if we return
all results at each step. The strategy of memory transfer decimation in 3. is
useful and faster than Python workflow in 5. and slower than 2. Note that 2.
is having no ids_put or memory transfers.

IWrap actor in 3. is 15% slower than Fortran in 2.
IWrap actor in 4. is 39% slower than Fortran in 2.
IWrap actor in 7. is 5% slower that Fortran in 2.

According to the difference of 7. and 3. it takes 0.03 seconds (9% of 0.37 s)
per timestep to IWrap all IDSs from Fortran to Python!
Empty input IDSs (10 IDS + codeparams) do not bring significant overhead.


"""
import sys
import imas
import os

from dina_iwrap_wf.actor import dina_iwrap_wf
from dina_iwrap_wf.common.runtime_settings import RunMode, DebugMode, SandboxMode

try:
    import wurlitzer
except ImportError:
    os.system("wget https://raw.githubusercontent.com/minrk/wurlitzer/main/wurlitzer.py")
    import wurlitzer


class ExampleWorkflowManager:

    def __init__(self):

        self.actor_dina_iwrap_wf = dina_iwrap_wf()
        self.output_entry = None
        self.summary = None
        self.equilibrium = None

    def init_workflow(self):
        # INPUT/OUTPUT CONFIGURATION
        shot                = 170
        run_in              = 6
        # input_user_or_path  = 'public'
        # input_database      = 'iter'
        run_out             = 10
        output_user_or_path = os.getenv('USER')
        output_database     = 'ITER'

        # # OPEN INPUT DATAFILE TO GET DATA FROM IMAS SCENARIO DATABASE
        # print('=> Open input datafile')
        # input_entry = imas.DBEntry(imas.imasdef.MDSPLUS_BACKEND,input_database,shot,run_in,input_user_or_path)
        # input_entry.open()
        
        # CREATE OUTPUT DATAFILE
        print('=> Create output datafile')
        self.output_entry = imas.DBEntry(imas.imasdef.MDSPLUS_BACKEND,output_database,shot,run_out,output_user_or_path)
        self.output_entry.create()

        # # # # # # # # Initialization of ALL actors  # # # # # # # #
        actor_run_mode = os.getenv( 'ACTOR_RUN_MODE', 'NORMAL')
        runtime_settings = self.actor_dina_iwrap_wf.get_runtime_settings()
        runtime_settings.sandbox.mode = SandboxMode.MANUAL
        runtime_settings.sandbox.path = os.getcwd()

        if actor_run_mode == 'STANDALONE':
            print('Running STANDALONE version.')
            runtime_settings.run_mode = RunMode.STANDALONE

        code_parameters = self.actor_dina_iwrap_wf.get_code_parameters()
        code_parameters.set_parameter( 'parameters/step_max', 200 )
        code_parameters.set_parameter('parameters/output/decimation', 10)        
        step_max = code_parameters.get_parameter('parameters/step_max')
        decimation = code_parameters.get_parameter('parameters/output/decimation')
        print(f'{step_max=}, {decimation=}')
        
        self.actor_dina_iwrap_wf.initialize(runtime_settings=runtime_settings, code_parameters=code_parameters)
        #self.actor_dina_iwrap_wf.code_parameters.parameters= '/gss_efgw_work/scratch/g2bpalak/tmp/xml_new_location.xml'


        # READ INPUT IDSS FROM LOCAL DATABASE
        #time_slice          = 200.
        #print('=> Read input IDSs')
        #self.equilibrium = input_entry.get_slice('equilibrium', time_slice, 1)


        self.equilibrium_in = imas.equilibrium()
        self.magnetics_in = imas.magnetics()
        self.em_coupling_in = imas.em_coupling()
        self.pf_active_in = imas.pf_active()
        self.pf_passive_in = imas.pf_passive()
        self.wall_in = imas.wall()
        self.core_profiles_in = imas.core_profiles()
        self.core_sources_in = imas.core_sources()
        self.transport_solver_numerics_in = imas.transport_solver_numerics()
        self.pulse_schedule_in = imas.pulse_schedule()
        self.pulse_schedule_term_in = imas.pulse_schedule()

    def execute_workflow(self):

        # EXECUTE PHYSICS CODE
        print('=> Execute physics code')
        while int(self.actor_dina_iwrap_wf.get_state()) < 2:
            with wurlitzer.pipes() as (out, err): 
                (self.pf_active_out,  self.summary_out, self.magnetics_out,
                 self.pf_passive_out, self.equilibrium_out, self.core_profiles_out,
                 self.core_sources_out, self.core_transport_out, self.bndcond_out
                ) = self.actor_dina_iwrap_wf(self.equilibrium_in, self.magnetics_in, 
                        self.em_coupling_in, self.pf_active_in, self.pf_passive_in,
                        self.wall_in, self.core_profiles_in, self.core_sources_in,
                        self.transport_solver_numerics_in, self.pulse_schedule_in, 
                        self.pulse_schedule_term_in)
            print('slices ', *self.summary_out.time)
            #print('out=', out.read())
            print('v_loop=',self.summary_out.global_quantities.v_loop.value)
            print('ip=', self.summary_out.global_quantities.ip.value)
            print('t=', self.summary_out.time)
          # SAVE IDSs INTO OUTPUT FILE
            #print( '=> Export output IDSs to local database: ', i )
            #self.output_entry.put( self.equilibrium )
            #print( 'Done exporting.' )


        self.actor_dina_iwrap_wf.finalize()

    def end_workflow(self):
        
        # Finalize ALL actors 
        self.actor_dina_iwrap_wf.finalize()

        
    
        #other finalizastion actions

        self.output_entry.close()



manager = ExampleWorkflowManager()

manager.init_workflow()
manager.execute_workflow()
manager.end_workflow()






