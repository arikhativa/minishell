/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_redirect.t.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:25:44 by yoav             ###   ########.fr       */
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
	input = util_create_tab(5, "echo", "a", ">", "file", "b");
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	*ret = sp;
}

void	test_commander_redirect(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_cmd			*cmd;

	init_sp(&sp);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	cmd = sp->cmd_list->lst->value;
	CU_ASSERT_STRING_EQUAL(cmd->argv[0], "echo");
	CU_ASSERT_STRING_EQUAL(cmd->argv[1], "a");
	CU_ASSERT_STRING_EQUAL(cmd->argv[2], "b");
	shell_op_destroy(&sp);
}
