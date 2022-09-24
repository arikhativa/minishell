/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/06 09:52:33 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "executer.h"

void	test_basic_executer(void)
{
	t_error_code		err;
	t_cmd				*c;
	char				**args;
	static char			*filename = "del";

	err = cmd_create(&c);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	args = util_create_tab(2, "/usr/bin/touch", filename);
	cmd_add_arg(c, args[0]);
	cmd_add_arg(c, args[1]);
	cmd_add_arg(c, args[2]);
	executer_run_cmd(c);
	if (access(filename, F_OK))
		CU_FAIL("file was not created");
	if (remove(filename))
		CU_FAIL("file was not deleted");
	cmd_destroy(&c);
	tab_deep_destroy(&args);
}
