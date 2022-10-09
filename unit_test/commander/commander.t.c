/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 12:14:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "commander.h"

static void	init_sp(t_shell_op **ret)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(8, "cat", "file", "|", "grep", "-v", "a", "\n", \
		"pwd");
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	*ret = sp;
}

void	test_commander(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_cmd			*cmd;

	init_sp(&sp);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	cmd = sp->cmd_list->lst->value;
	CU_ASSERT_STRING_EQUAL(cmd->argv[0], "cat");
	CU_ASSERT_STRING_EQUAL(cmd->argv[1], "file");
	CU_ASSERT_PTR_NULL(cmd->argv[2]);
	cmd = sp->cmd_list->lst->next->value;
	CU_ASSERT_STRING_EQUAL(cmd->argv[0], "grep");
	CU_ASSERT_STRING_EQUAL(cmd->argv[1], "-v");
	CU_ASSERT_STRING_EQUAL(cmd->argv[2], "a");
	CU_ASSERT_PTR_NULL(cmd->argv[3]);
	cmd = sp->cmd_list->lst->next->next->value;
	CU_ASSERT_STRING_EQUAL(cmd->argv[0], "pwd");
	CU_ASSERT_PTR_NULL(cmd->argv[1]);
	shell_op_destroy(&sp);
}
