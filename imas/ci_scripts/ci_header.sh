#!/bin/bash

# SET UP ENVIRONMENT FOR COMPILATION
. /usr/share/Modules/init/sh
module use /work/imas/etc/modulefiles
module use /work/imas/etc/modules/all
shopt -s expand_aliases

# # THE HOME AND USER ENVIRONMENT VARIABLES DO NOT EXIST IN BAMBOO!!! (NEEDED BY KEPLER)
# if [ -z "$HOME" ]; then
#   export HOME=/root/
# fi
# 
# if [ -z "$USER" ]; then
#   export USER=root
# fi

module purge 2> /dev/null
module load imas/3.10.1/ual/3.6.0

module load kepler/2.5p2-2.1.3
export KEPLER_DIR=~/Keplerdir
#module load Keplerdir/my2.5p2-2.1.3

# KEPLER ENVIRONMENT VARIABLES
KEPLERMODULE=Keplerdir/my2.5p2-2.1.3
module load $KEPLERMODULE

module load fc2k/4.2.6
export _JAVA_OPTIONS="-Xss20m -Xms1g -Xmx4g" #stack size
module load matlab/2012b
imasdb test

# # FOR PYUAL (PYTHON WORKFLOWS)
# export PYTHONPATH=/work/imas/core/pyual:$PYTHONPATH
# 
# # CHOOSE THE COMPILER 0=GFORTRAN (DEFAULT IF VARIABLE IS NOT SET), 1=INTEL
# if [ -z "$FCOMPILER" ]; then
#     echo 'FCOMPILER not set'
#     echo '=> Use gfortran as default'
#     export FCOMPILER=gfortran
# else
#    if [ "$FCOMPILER" == "ifort" ]; then
#       echo '$FCOMPILER set to intel'
#     else
#       echo '$FCOMPILER set to gfortran'
#     fi
# fi
# 
# # INTEL
# if [ "$FCOMPILER" == "ifort" ]; then
#   module load intel/12.0.2
#   module load mpich2/3.1.3-intel
#   module load xmllib/2.0.0-imas-3.7.4-intel-12.0.2
#   OBJ=obj_ifort
# else
# # GFORTRAN
#   module load mpich2/3.1.3-gnu
#   module load xmllib/2.0.0-imas-3.7.4-GCC-4.8.3
#   OBJ=obj_gfortran
# fi

module list


