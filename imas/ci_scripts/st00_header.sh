#!/bin/bash
# Bamboo CI script to build 
#
# This script expects to be run from the repository root directory

# set -e -o pipefail
echo "Loading modules..."

# Set up environment such that module files can be loaded
if test -f /etc/profile.d/modules.sh ;then
. /etc/profile.d/modules.sh
else
. /usr/share/Modules/init/sh
fi
module purge

# Check for TOOLCHAIN
TOOLCHAIN=${TOOLCHAIN:-foss-2023b}
# Load modules that correspond to toolchain
case "$TOOLCHAIN" in
  *-2023b)
echo "... 2023b"
module load "${MODULES[@]}"
MODULES=(
    iWrap/1.0.0-GCCcore-13.2.0
)
  ;;&
  *foss-2023b)
echo "... foss-2023b"
MODULES=(${MODULES[@]}
    IMAS/3.39.0-2024.09-foss-2023b
    Viz/2.8.0-foss-2023b
    XMLlib/3.3.2-GCC-13.2.0
)
CMAKE_ARGS=(${CMAKE_ARGS[@]}
    -DCMAKE_C_COMPILER=${CC:-gcc}
    -DCMAKE_CXX_COMPILER=${CXX:-g++}
)
  ;;&
  *intel-2023b)
echo "... intel-2023b"
MODULES=(${MODULES[@]}
    IMAS/3.39.0-2024.09-intel-2023b
    Viz/2.8.0-intel-2023b
    XMLlib/3.3.2-intel-compilers-2023.2.1
)
CMAKE_ARGS=(${CMAKE_ARGS[@]}
    -DCMAKE_C_COMPILER=${CC:-icx}
    -DCMAKE_CXX_COMPILER=${CXX:-icpx}
)
  ;;
esac
echo "${MODULES[@]}" | tr " " "\n"

module load "${MODULES[@]}"

echo "Done loading modules"


export PYTHONPATH=${HOME}/IWRAP_ACTORS:${PYTHONPATH}
export FCOMPILER=gfortran
export CC=gcc
export DINA_ROOT=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd)
export GIT_URL=$(git remote get-url origin)
export GIT_COMMIT_ID=$(git rev-parse --verify HEAD)
export GIT_VERSION=$(git describe --tags --abbrev=0)

echo $DINA_ROOT
echo $GIT_URL
echo $GIT_COMMIT_ID
echo $GIT_VERSION

