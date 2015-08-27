#!/bin/bash 

if [ $# -eq 1 ]
then
    WKFL=$1
else
    WKFL=SimpleAddition.xml
fi
${KEPLER}/kepler.sh ${WKFL} 

#echo 0 > ~/ITERIS/TEST/IMAS_flag
#echo 0 > ~/ITERIS/TEST/PCS_flag




