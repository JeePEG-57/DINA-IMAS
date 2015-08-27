#!/bin/bash 
sleep 7
if [ $# -eq 1 ]
then
    WKFLAUX=$1
else
    WKFLAUX=SimpleAddition.xml
fi
WKFL=`echo $WKFLAUX | awk -F "/" '{ print $NF }'`
while [ -z $WDID ]; do
       WDID=`echo $(xdotool search ${WKFL}\$) 2> /dev/null`
       sleep 5
done
echo $WDID > ~/ITERIS/TEST/KEPID 

#echo "valeur de WDID=:$WDID" 

#xdotool windowactivate ${WDID} && xdotool key ctrl\+r

KEP_PROCESSPPID=`ps -eaf | /bin/grep ${WKFL} | /bin/grep java | awk '{print $2}' `
#echo "KEP_PROCESSPPID :$KEP_PROCESSPPID"

KEP_PROCESSPID=`ps -eaf | /bin/grep ${KEP_PROCESSPPID} | awk '$3 == '$KEP_PROCESSPPID' {print $2}' `
echo "KEP_PROCESSPID :$KEP_PROCESSPID"

echo $KEP_PROCESSPPID >> ~/ITERIS/TEST/KEPID 
echo $KEP_PROCESSPID >> ~/ITERIS/TEST/KEPID



