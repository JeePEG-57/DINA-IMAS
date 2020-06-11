# check psi from 2 equilibrium IDS's
import imas, os

shot    = 170
tokamakname = 'test'
user = os.getenv('USER')
version = os.getenv('IMAS_VERSION')[0]

run1 = 20 # time slice
time1 = 5.654
run2 = 30 # single equilibrium

input1 = imas.ids(shot,run1,0,0)
input1.open_env(user,tokamakname,version)
input1.equilibrium.getSlice(time1,2) # 2 closest interpolation

input2 = imas.ids(shot,run2,0,0)
input2.open_env(user,tokamakname,version)
input2.equilibrium.get()

# compare psi2d
psi1 = input1.equilibrium.time_slice[0].profiles_2d[0].psi
psi2 = input2.equilibrium.time_slice[0].profiles_2d[0].psi

psi1max = max(map(max, psi1))
#print(psi1max)
psi2max = max(map(max, psi2))
#print(psi2max)
dpsi = max(map(max, abs(psi1-psi2)))/abs(psi1max)
#print('dpsi = ',dpsi)


dpsiLimit = 5e-4
if dpsi < dpsiLimit:
  print('psi accuracy OK ',dpsi, dpsiLimit)
else:
  print('ERROR: psi accuracy NOT REACHED ',dpsi, dpsiLimit)
