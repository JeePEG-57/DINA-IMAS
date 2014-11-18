#!/bin/bash
# This script starts Kepler.
# Run with -h to see all command-line options.
# This script is auto-generated.

CUR_DIR=`pwd`
SCRIPT_DIR=`dirname $BASH_SOURCE`
#cd $SCRIPT_DIR
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${MATLAB}/bin/glnxa64
i=0
for arg in $@
do
   i=$((i+1))
   if [ $i == $# ]
      then
        var=`echo ${!i}`
        if [[ "${var:0:1}" != "-" && "${var:0:1}" != "/" ]]
        then
           auxargument=`echo $auxargument "$PWD"'/'"$var"`
        else
           auxargument=`echo $auxargument $var`
        fi
      else
        auxargument=`echo $auxargument ${!i}`
   fi
done
java -classpath $KEPLER/build-area/lib/ant.jar:$KEPLER/kepler.jar org.kepler.build.runner.Kepler `echo $auxargument`
#cd $CUR_DIR
#valgrind -v --tool=memcheck --leak-check=yes java -classpath $KEPLER/build-area/lib/ant.jar:$KEPLER/kepler.jar org.kepler.build.runner.Kepler `echo $auxargument`
