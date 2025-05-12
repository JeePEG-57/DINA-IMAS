# ------------------------------------
# ACTOR USAGE TEST EXAMPLE
# ------------------------------------

# NEEDED MODULES
import imas,os
from imas import imasdef
import numpy
import xml.etree.ElementTree as ET
from dina_green.actor import dina_green



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




config = "test_wf_parameters.xml"

if (type(config) == str):
    tree = ET.parse(config)
root = tree.getroot()

user_default = os.getenv('USER')

Time_Start = 0.
InterpStart = imasdef.CLOSEST_INTERP

# INPUT/OUTPUT CONFIGURATION
IMAS_PFA, status = get_dbentry(root.find('input_pf_active'), user_default)
IMAS_PFA.open()
pf_active = IMAS_PFA.get_slice('pf_active', Time_Start, InterpStart)
IMAS_PFA.close()

IMAS_PFP, status = get_dbentry(root.find('input_pf_passive'), user_default)
IMAS_PFP.open()
pf_passive = IMAS_PFP.get_slice('pf_passive', Time_Start, InterpStart)
IMAS_PFP.close()

IMAS_MAG, status = get_dbentry(root.find('input_magnetics'), user_default)
if (status == 0):
    IMAS_MAG.open()
    magnetics = IMAS_MAG.get_slice('magnetics', Time_Start, InterpStart)
    IMAS_MAG.close()
else:
    magnetics = imas.magnetics()
    magnetics.ids_properties.homogeneous_time=2

IMAS_EQ, status = get_dbentry(root.find('input_equilibrium'), user_default)
if (status == 0):
    IMAS_EQ.open()
    equilibrium = IMAS_EQ.get_slice('equilibrium', Time_Start, InterpStart)
    IMAS_EQ.close()
else:
    equilibrium = imas.equilibrium()
    grid = root.find('grid')
    nr = int(grid.find('nr').text)
    nz = int(grid.find('nz').text)
    r1 = float(grid.find('r1').text)
    r2 = float(grid.find('r2').text)
    z1 = float(grid.find('z1').text)
    z2 = float(grid.find('z2').text)
    equilibrium.ids_properties.homogeneous_time=1
    equilibrium.time_slice.resize(1)
    equilibrium.time.resize(1)
    equilibrium.time[0] = 0.
    equilibrium.time_slice[0].profiles_2d.resize(1)
    equilibrium.time_slice[0].profiles_2d[0].type.index = 0
    equilibrium.time_slice[0].profiles_2d[0].grid_type.index = 1 # Rectangular a la eqdsk
    equilibrium.time_slice[0].profiles_2d[0].grid.dim1 = numpy.linspace(r1, r2, num=nr)
    equilibrium.time_slice[0].profiles_2d[0].grid.dim2 = numpy.linspace(z1, z2, num=nz)


# CREATE OUTPUT DATAFILE
print('=> Create output datafile')
IMAS_OUT, status = get_dbentry(root.find('output'), user_default)
IMAS_OUT.create()


# CREATE AND INITIALIZE ACTOR
dina_green_actor = dina_green()
dina_green_actor.initialize()
  
# EXECUTE ACTOR
print('=> Execute physics code', flush=True)
try:
    em_coupling = dina_green_actor(pf_active, pf_passive, magnetics, equilibrium)
except Exception as error_message:
    print('ERROR in run_physics_code',str(error_message))
    exit(1)
# SAVE IDS INTO OUTPUT FILE
print('=> Append IDS slice to local database')
IMAS_OUT.put(em_coupling)
    

IMAS_OUT.close()
print('Done exporting.')




