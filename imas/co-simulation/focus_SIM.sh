#!/bin/bash 

MDLNAME=$1
while [ -z $WDID ]; do
       WDID=`echo $(xdotool search ${MDLNAME}) 2> /dev/null`
       sleep 5
done
echo $WDID  
xdotool windowactivate ${WDID} 



