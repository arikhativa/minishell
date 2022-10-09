#!/bin/bash

# run test and save in TEST_RES
$ROOT_DIR/$TEST_EXEC > $ROOT_DIR/$TEST_RES
# print res
cat $ROOT_DIR/$TEST_RES
# check for failed tests
STT=$( cat $ROOT_DIR/$TEST_RES | grep -a "asserts" | awk '{print $5}')
# return the status as true/false
if [[ $STT -eq 0 ]]
then
	true
else
	false
fi
