#!/bin/bash

run_with_valgrind()
{
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$VALGRIND_OUTPUT $ROOT_DIR/$TEST_EXEC > $ROOT_DIR/$TEST_RES
}

check_leaks()
{
	set_is_valgrind_installed
	if [ $IS_VALGRIND_INSTALLED -eq $TRUE ]; then
		local STT=$(grep "ERROR SUMMARY:" $VALGRIND_OUTPUT | awk '{print $4}')

		if [ "$STT" == "0" ] ; then
			printf "No Leaks :)"
			return $SUCCESS
		else
			cat $VALGRIND_OUTPUT
			return $ERROR
		fi
	else
		printf "valgrind is not installed"
	fi
}

set_is_valgrind_installed()
{
	local OUT_PUT=$(command -v valgrind)
	if [ "$OUT_PUT" == "" ] ; then
		IS_VALGRIND_INSTALLED=$FALSE
	else
		IS_VALGRIND_INSTALLED=$TRUE
	fi
}

