/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_return_val.t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 16:31:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "executer.h"
#include "commander.h"
#include "laxer.h"

static void	test1(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(1, "no-cmdForSure");
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = executer_run_all_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	CU_ASSERT_EQUAL(sp->last_cmd_stt, ERROR);
	shell_op_destroy(&sp);
}

static void	test2(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(4, "no-cmdForSure", "|", "touch", "a");
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = executer_run_all_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	CU_ASSERT_EQUAL(sp->last_cmd_stt, SUCCESS);
	shell_op_destroy(&sp);
	remove("a");
}

void	test_return_value(void)
{
	test1();
	test2();
}
