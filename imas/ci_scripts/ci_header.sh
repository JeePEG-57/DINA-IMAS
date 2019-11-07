#!/bin/bash

# SET UP ENVIRONMENT FOR COMPILATION
. /usr/share/Modules/init/sh
# module use /work/imas/etc/attic
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
# module load imas/3.10.1/ual/3.6.0
# module load IMAS/3.23.3-4.1.5
module load IMAS/3.25.0-4.3.0

# KEPLER ENVIRONMENT VARIABLES

# module load kepler/2.5p2-2.1.3
# export KEPLER_DIR=~/Keplerdir
# #module load Keplerdir/my2.5p2-2.1.3
# # KEPLERMODULE=Keplerdir/my2.5p2-2.1.3
# # module load $KEPLERMODULE
# KEPLERMODULE=my2.5p2-2.1.3
# module load Keplerdir/$KEPLERMODULE

KEPLERVERSON=Kepler/2.5p4-3.0.5
# KEPLERVERSON=Kepler/2.5p2-2.1.4
# KEPLERVERSON=Kepler/2.5p4-2.1.5
module load $KEPLERVERSON

# KEPLERMODULE=MY2.5p2-2.1.4
# KEPLERMODULE=MY2.5p4-2.1.5
# module load Keplerdir/$KEPLERMODULE

KEPLERMODULE=MY2.5p4-3.0.5
if kepler_avail 2> /dev/null | grep -q $KEPLERMODULE; then
   echo kepler_load $KEPLERMODULE
   kepler_load $KEPLERMODULE
else
   echo "run bash ci_build.sh keplerinstall"
   return
fi

# module load fc2k/4.2.6
module load FC2K/4.6.5

# export _JAVA_OPTIONS="-Xss20m -Xms1g -Xmx4g" #stack size
module load MATLAB/2018a

imasdb test

module load TotalView

export _JAVA_OPTIONS="-Xss20m -Xms1g -Xmx4g" #stack size

module load PyQt5

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


