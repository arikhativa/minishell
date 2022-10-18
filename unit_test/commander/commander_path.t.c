/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_path.t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:44:02 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 14:06:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "unit_test_util.h"
#include "unit_test.h"
#include "commander.h"

static char	g_buff[500] = {0};

static void	modify_path(t_shell_op *sp)
{
	getcwd(g_buff, sizeof(g_buff));
	strcat(g_buff, "/unit_test/resources/");
	env_unsetvar(sp->envp, PATH_KEY);
	env_setvar(&(sp->envp), PATH_KEY, g_buff);
}

static void	test1(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_cmd			*cmd;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	modify_path(sp);
	shell_op_set_input(sp, util_create_tab(1, "bin_with_prem"));
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	cmd = sp->cmd_list->lst->value;
	CU_ASSERT_PTR_NOT_NULL_FATAL(cmd->exec_path);
	CU_ASSERT_EQUAL(cmd->stt, OK);
	CU_ASSERT_STRING_EQUAL(cmd->exec_path, strcat(g_buff, "bin_with_prem"));
	shell_op_destroy(&sp);
}

static void	test2(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_cmd			*cmd;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	shell_op_set_input(sp, util_create_tab(1, \
		"./unit_test/resources/bin_with_no_prem"));
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	cmd = sp->cmd_list->lst->value;
	CU_ASSERT_PTR_NOT_NULL_FATAL(cmd->exec_path);
	CU_ASSERT_EQUAL(cmd->stt, PREM_DENIED);
	shell_op_destroy(&sp);
}

static void	test3(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_cmd			*cmd;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	shell_op_set_input(sp, util_create_tab(1, \
		"no-bin-trust-me"));
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	cmd = sp->cmd_list->lst->value;
	CU_ASSERT_PTR_NULL_FATAL(cmd->exec_path);
	CU_ASSERT_EQUAL(cmd->stt, CMD_NOT_FOUND);
	shell_op_destroy(&sp);
}

void	test_path_var_search(void)
{
	test1();
	test2();
	test3();
}
