# ------------------------------------
# ACTOR USAGE TEST EXAMPLE
# ------------------------------------

# NEEDED MODULES
import imas,os
from imas import imasdef
import numpy
import xml.etree.ElementTree as ET
from kav_mag_contr.actor import kav_mag_contr



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

pulse_schedule = IMAS_SCEN.get('pulse_schedule')
pulse_schedule_term = IMAS_SCEN.get('pulse_schedule', occurrence=1)
pf_active0 = IMAS_SCEN.get_slice('pf_active', Time_Start, InterpStart)
equilibrium0 = IMAS_SCEN.get_slice('equilibrium', Time_Start, InterpStart)

IMAS_SCEN.close()

bndcond_in = imas.transport_solver_numerics()

# CREATE OUTPUT DATAFILE
print('=> Create output datafile')
IMAS_OUT, status = get_dbentry(root.find('output'), user_default)
IMAS_OUT.create()


# CREATE AND INITIALIZE ACTOR
kmc = kav_mag_contr()
kmc.initialize()
  
# EXECUTE ACTOR
print('=> Execute physics code')
try:
    pf_active = kmc(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0)
except Exception as error_message:
    print('ERROR in run_physics_code',str(error_message))
    exit(1)
# SAVE IDS INTO OUTPUT FILE
print('=> Append IDS slice to local database')

IMAS_OUT.put(pulse_schedule)
IMAS_OUT.put(pulse_schedule_term, occurrence=1)
IMAS_OUT.put(equilibrium0)
IMAS_OUT.put(pf_active)


IMAS_OUT.close()
print('Done exporting.')




