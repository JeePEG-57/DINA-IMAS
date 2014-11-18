#!/bin/bash
# This script starts Kepler.
# Run with -h to see all command-line options.
# This script is auto-generated.

CUR_DIR=`pwd`
SCRIPT_DIR=`dirname $BASH_SOURCE`
cd $SCRIPT_DIR
java -classpath build-area/lib/ant.jar:kepler.jar org.kepler.build.runner.Kepler UseModuleManager "$@"
cd $CUR_DIR