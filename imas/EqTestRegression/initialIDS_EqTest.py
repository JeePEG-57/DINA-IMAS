# create initial IDS
import imas, os

shot    = 170
run = 1
tokamakname = 'test'
user = os.getenv('USER')
version = os.getenv('IMAS_VERSION')[0]

imasdb = imas.ids(shot,run,0,0)
imasdb.create_env(user,tokamakname,version)

