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
echo $input test
echo "-----------------"

# ----------------------------------------------------------------------------------------------------------

if [ $input == 'flat' ]; then

  # ---> Extract test_dina_to_imas artifact
  cd imas/test_flat
  tar -xzvf test_flat.tgz || exit 1

  # ---> Inductance matrices calculation
  ./test_flat | tee -a test_flat.log

# ----------------------------------------------------------------------------------------------------------

elif [ $input == 'initialIDS' ]; then

  # ---> Extract test_dina_to_imas artifact
  cd imas/interface
  tar -xzvf test_dina_to_imas.tgz || exit 1

  # ---> Create local database
  cd ../regression
  ../interface/test_dina_to_imas | tee -a test_dina_to_imas.log
  
  # ---> If some magic string is not found. Then error!
  test -n "$(grep 'All finished' test_dina_to_imas.log)" || { echo "Test execution did not succeed.">&2 ; exit 1 ;}
  # ---> If some bloody string is found. Then error!
  test -z "$(grep -i 'ERROR' test_dina_to_imas.log)" || { echo "Test did not succeed.">&2 ; exit 1 ;}

# ----------------------------------------------------------------------------------------------------------

elif [ $input == 'regression' ]; then

  # ---> Extract test_circ artifact
  cd imas/circ
  tar -xzvf test_circ.tgz || exit 1

  # ---> Copy reference IDS's to local imasdb
  imasdb test
  cd ../regression
  tar xvf IDS_ref.tar --strip 1 -C $MDSPLUS_TREE_BASE_0
  
  ../circ/test_circ | tee -a test_circ.log

#   # ---> Extract executable from the artifact and run the wrapper
#   if [ $input == 'exewrapper1' ]; then
#     tar xzf physics_i_wrapper.tar.gz || exit 1
#     ./wrapper_i.exe | tee -a wrapper.txt 
#   elif [ $input == 'exewrapper2' ]; then
#     tar xzf physics_ii_wrapper.tar.gz || exit 1
#     ./wrapper_ii.exe | tee -a wrapper.txt 
#   fi

  # ---> If some magic string is not found. Then error!
  test -n "$(grep 'DINA_IMAS Exiting cleanly' test_circ.log)" || { echo "Test execution did not succeed.">&2 ; exit 1 ;}
  # ---> If some bloody string is found. Then error!
#   test -z "$(grep -i 'ERROR' test_circ.log)" || { echo "Test did not succeed.">&2 ; exit 1 ;}
  test -z "$(grep 'ERROR' test_circ.log)" || { echo "Test did not succeed.">&2 ; exit 1 ;}

else

  # Error
  echo "Bad input option => Exit."
  exit 1

fi
