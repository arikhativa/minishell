#!/bin/bash

ERROR=-1
SUCCESS=0
TRUE=1
FALSE=0
IS_VALGRIND_INSTALLED=$FALSE
IS_NORMINETTE_INSTALLED=$FALSE
IS_MEM_LEAKS=$FALSE
BASEDIR=$(dirname "$0")

source $BASEDIR/unit_test.sh
source $BASEDIR/valgrind.sh
source $BASEDIR/norm.sh

case $1 in
	unit_test)
		unit_test ;;
	memory)
		check_leaks ;;
	norm)
		check_norm ;;
	*)
		printf "Invalid Arg (or missing)" ;;
esac
