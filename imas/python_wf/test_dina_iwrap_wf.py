import sys

import imas,os

from dina_iwrap_wf.actor import dina_iwrap_wf
from dina_iwrap_wf.common.runtime_settings import RunMode, DebugMode, SandboxMode



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
        self.actor_dina_iwrap_wf.initialize(runtime_settings=runtime_settings, code_parameters=code_parameters)

        #self.actor_dina_iwrap_wf.code_parameters.parameters= '/gss_efgw_work/scratch/g2bpalak/tmp/xml_new_location.xml'


        # READ INPUT IDSS FROM LOCAL DATABASE
        #time_slice          = 200.
        #print('=> Read input IDSs')
        #self.equilibrium = input_entry.get_slice('equilibrium', time_slice, 1)

    
    def execute_workflow(self):

        # EXECUTE PHYSICS CODE
        print('=> Execute physics code')
        #self.actor_dina_iwrap_wf.initialize()
        #for i in range( 11 ):
        while int(self.actor_dina_iwrap_wf.get_state()) < 2:
            (self.pf_active_out,
             self.summary_out,
             self.magnetics_out,
             self.pf_passive_out,
             self.equilibrium_out,
             self.core_profiles_out,
             self.core_sources_out,
             self.core_transport_out,
             self.bndcond_out) = self.actor_dina_iwrap_wf()
            # SAVE IDSS INTO OUTPUT FILE
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






