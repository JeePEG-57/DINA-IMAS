#!/bin/bash

# source $(dirname $0)/ci_header.sh
source $(dirname ${BASH_SOURCE[0]})/ci_header.sh

# DEFINE INPUT / OUTPUT - CHECK THE NUMBER OF ARGUMENTS
if [ $# == 1 ]; then
  input=$1
else
  echo -e "-------------------------------"
  echo -e "Invalid arguments. Usage:"
  echo -e "${BASH_SOURCE[0]} <selection>"
  echo -e "-------------------------------"
  exit 1
fi

echo "-----------------"
echo $input build
echo "-----------------"

# ----------------------------------------------------------------------------------------------------------

if [ $input == 'keplerinstall' ]; then

  yes | kepler_install $KEPLERMODULE
  
  # ---> Check if Kepler is correctly installed 
  ls $KEPLER/build-area/build.xml  || exit 1

#   # ---> kepler artifact
#   ls -ltr
#   rm MyKepler.tgz
#   tar cvfz MyKepler.tgz ~/$KEPLERMODULE

# ----------------------------------------------------------------------------------------------------------

elif [ $input == 'dina' ]; then

  make clean
  make || exit 1
  
  # ---> test_dina_to_imas artifact
  cd imas/interface
  tar -czvf test_dina_to_imas.tgz test_dina_to_imas || exit 1

# ----------------------------------------------------------------------------------------------------------

elif [ $input == 'regression' ]; then

  cd imas/circ/

  make clean
  make || exit 1
  
  # ---> test_circ artifact
  tar -czvf test_circ.tgz test_circ || exit 1

# ----------------------------------------------------------------------------------------------------------

else

  # Error
  echo "Bad input option => Exit."
  exit 1

fi
