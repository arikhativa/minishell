#!/bin/bash

check_norm()
{
	set_is_norminette_installed
	norminette $ROOT_DIR > $ROOT_DIR/$NORMINETTE_OUTPUT
	if [ $IS_NORMINETTE_INSTALLED -eq $TRUE ]; then
		local STT=$(grep "Error" $NORMINETTE_OUTPUT | wc -l)

		if [ "$STT" -eq "0" ] ; then
			printf "OK NORM :)"
			return $SUCCESS
		else
			grep "Error" $NORMINETTE_OUTPUT
			return $ERROR
		fi
	else
		printf "norminette is not installed"
	fi
}

set_is_norminette_installed()
{
	local OUT_PUT=$(command -v norminette)
	if [ "$OUT_PUT" == "" ] ; then
		IS_NORMINETTE_INSTALLED=$FALSE
	else
		IS_NORMINETTE_INSTALLED=$TRUE
	fi
}
