#!/bin/bash

run_tester()
{
	set_is_valgrind_installed
	if [ $IS_VALGRIND_INSTALLED -eq $TRUE ]; then
		run_with_valgrind
	else
		$ROOT_DIR/$TEST_EXEC > $ROOT_DIR/$TEST_RES
	fi
}

unit_test()
{
	# run test and save in TEST_RES
	run_tester

	# print res
	cat $ROOT_DIR/$TEST_RES

	# check for failed tests
	STT=$( cat $ROOT_DIR/$TEST_RES | grep -a "asserts" | awk '{print $5}')

	# return the status as true/false
	if [[ $STT -eq 0 ]]
	then
		return $SUCCESS
	else
		return $ERROR
	fi
}

