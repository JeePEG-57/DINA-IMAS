# G-EQDSK format description
# https://w3.pppl.gov/ntcc/TORAY/G_EQDSK.pdf

import numpy as np

# Amount of columns in the output file
ncol = 5

def writeReal(f, v):
  f.write("% 16.9E"%v)

def write1d(f, v):
  n = len(v)
  for i in range(n):
    writeReal(f, v[i])
    if i>0 and ((i+1)%ncol == 0 or i == n-1):
      f.write("\n")

def write2d(f, v):
  sh = np.shape(v)
  n = sh[0]
  m = sh[1]
  for j in range(m):
    for i in range(n):
      writeReal(f, v[i,j])
      k = j*n+i
      if k>0 and ((k+1)%ncol == 0 or k == n*m-1):
        f.write("\n")


def write(f, data):
  #Write a G-EQDSK file

  if isinstance(f, str):
      # If the input is a string, treat as file name
      with open(f, "w") as fh: # Ensure file is closed
          return write(fh, data) # Call again with file object


  # Write description
  f.write("geqdsk 0 " + str(data['nr']) + " " + str(data['nz']) + "\n")

  writeReal(f, data['rdim'])
  writeReal(f, data['zdim'])
  writeReal(f, data['rcentr'])
  writeReal(f, data['rleft'])
  writeReal(f, data['zmid'])
  f.write("\n")

  writeReal(f, data['rmaxis'])
  writeReal(f, data['zmaxis'])
  writeReal(f, data['simagx'])
  writeReal(f, data['sibdry'])
  writeReal(f, data['bcentr'])
  f.write("\n")

  writeReal(f, data['current'])
  writeReal(f, data['simagx'])
  writeReal(f, 0.0)
  writeReal(f, data['rmaxis'])
  writeReal(f, 0.0)
  f.write("\n")

  writeReal(f, data['zmaxis'])
  writeReal(f, 0.0)
  writeReal(f, data['sibdry'])
  writeReal(f, 0.0)
  writeReal(f, 0.0)
  f.write("\n")

  # Write the arrays
  write1d(f, data['fpol'])
  write1d(f, data['pressure'])
  write1d(f, data['ffprime'])
  write1d(f, data['pprime'])
  write2d(f, data['psirz'])
  write1d(f, data['qpsi'])

  # Boundary and limiter
  f.write(" " + str(data['nbbbs']) + " " + str(data['limitr']) + "\n")
  
  bnd = np.zeros(2*data['nbbbs'])
  for i in range(data['nbbbs']):
    bnd[2*i] = data['rbbbs'][i]
    bnd[2*i+1] = data['zbbbs'][i]
  
  wall = np.zeros(2*data['limitr'])
  for i in range(data['limitr']):
    wall[2*i] = data['rlim'][i]
    wall[2*i+1] = data['zlim'][i]
  
  write1d(f, bnd)
  write1d(f, wall)
  
