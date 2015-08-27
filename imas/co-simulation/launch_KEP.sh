#!/bin/sh

xterm -e "launch_IMAS.sh $1 2>&1 | tee log" &
