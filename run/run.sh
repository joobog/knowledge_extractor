#!/bin/bash


SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname ${SCRIPT}`
#LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${SCRIPTPATH}/..":$HOME/install/siox/lib:$HOME/install/boost/lib:$HOME/git/siox_ml_plugin/build
cd ${SCRIPTPATH}
siox-trace-reader --afile "$SCRIPTPATH/activities.dat" --plugin ML

