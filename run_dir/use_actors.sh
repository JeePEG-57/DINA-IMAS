#!/bin/bash

SCRIPTPATH=$(realpath "$(dirname "${BASH_SOURCE[0]}")")/actors
PYPATH=$PYTHONPATH

for f in $SCRIPTPATH/* ; do 
    if [ -d "$f" ]; then
	if [[ $PYPATH != *"$f"* ]]; then 
	    echo "Adding $(basename $f) to the PYTHONPATH"
	    PYPATH="$f:"$PYPATH
	else
	    echo "$(basename $f) already in PYTHONPATH"
	fi
    fi
done

export PYTHONPATH=$PYPATH
