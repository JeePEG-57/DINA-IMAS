# ------------------------------------
# ACTOR USAGE TEST EXAMPLE
# ------------------------------------

# NEEDED MODULES
import imas,os
from imas import imasdef
import numpy
import xml.etree.ElementTree as ET
from dina_imas.actor import dina_imas
from pprint import pprint
from dina_imas.common.runtime_settings import SandboxMode


def get_dbentry(root, user_default):
    if root == None:
        return None, -1
    usernode = root.find('user')
    if (usernode != None):
        username = usernode.text
    else:
        username = None
    if (username == None or username == ""):
        username = user_default
    database = root.find('database').text
    if database == None or database == '':
        return None, -1
    pulse = int(root.find('pulse').text)
    run = int(root.find('run').text)
    IMAS_DBEntry = imas.DBEntry(imasdef.MDSPLUS_BACKEND, database, pulse, run, username, data_version = '3')
    status,_ = IMAS_DBEntry.open()
    if status == 0:
        IMAS_DBEntry.close()
    return IMAS_DBEntry, status




config = "test_actor_parameters.xml"

if (type(config) == str):
    tree = ET.parse(config)
root = tree.getroot()

user_default = os.getenv('USER')

Time_Start = float(root.find('input_scenario').find('time_start').text)
InterpStart = imasdef.CLOSEST_INTERP

# INPUT/OUTPUT CONFIGURATION
IMAS_SCEN, status = get_dbentry(root.find('input_scenario'), user_default)
IMAS_SCEN.open()

print("Reading input database at t=%f"%(Time_Start))

if True:
    em_coupling = IMAS_SCEN.get_slice('em_coupling', Time_Start, InterpStart)
    wall = IMAS_SCEN.get_slice('wall', Time_Start, InterpStart)
    pulse_schedule = IMAS_SCEN.get('pulse_schedule')
    pf_active0 = IMAS_SCEN.get_slice('pf_active', Time_Start, InterpStart)
    pf_passive0 = IMAS_SCEN.get_slice('pf_passive', Time_Start, InterpStart)
    magnetics0 = IMAS_SCEN.get_slice('magnetics', Time_Start, InterpStart)
    equilibrium0 = IMAS_SCEN.get_slice('equilibrium', Time_Start, InterpStart)
    core_profiles0 = IMAS_SCEN.get_slice('core_profiles', Time_Start, InterpStart)
    core_sources0 = IMAS_SCEN.get_slice('core_sources', Time_Start, InterpStart)

IMAS_SCEN.close()

bndcond_in = imas.transport_solver_numerics()

# CREATE OUTPUT DATAFILE
print('=> Create output datafile')
IMAS_OUT, status = get_dbentry(root.find('output'), user_default)
IMAS_OUT.create()


# CREATE AND INITIALIZE ACTOR
dina_imas_actor = dina_imas()
#dina_imas_actor.initialize()

# Set this directory as sandbox to use imp folder
runtime_settings = dina_imas_actor.get_runtime_settings()
runtime_settings.sandbox.mode = SandboxMode.MANUAL
runtime_settings.sandbox.path = './'
dina_imas_actor.initialize(runtime_settings=runtime_settings)

# EXECUTE ACTOR
print('=> Execute physics code')
try:
    (equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport, summary) = dina_imas_actor(em_coupling, equilibrium0, magnetics0, pf_active0, pf_passive0, wall, core_profiles0, core_sources0,
    bndcond_in, pulse_schedule)
except Exception as error_message:
    print('ERROR in run_physics_code',str(error_message))
    exit(1)
    
# SAVE IDS INTO OUTPUT FILE
print('=> Append IDS slice to local database')
IMAS_OUT.put(em_coupling)
IMAS_OUT.put(wall)
IMAS_OUT.put(pulse_schedule)
IMAS_OUT.put(equilibrium)
IMAS_OUT.put(magnetics)
IMAS_OUT.put(pf_active)
IMAS_OUT.put(pf_passive)
IMAS_OUT.put(core_profiles)
IMAS_OUT.put(core_sources)
IMAS_OUT.put(core_transport)
IMAS_OUT.put(summary)
    

IMAS_OUT.close()
print('Done exporting.')




