/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter_in.t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/27 11:46:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "redirecter.h"
#include "commander.h"
#include "laxer.h"

#define IN_FILE0	"unit_test/resources/redirect_filein"

static void	setup(t_shell_op **ret)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(3, "cat", "<", IN_FILE0);
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = redirecter_setup_files(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	*ret = sp;
}

static t_redirect	*get_redirect_in(t_shell_op *sp)
{
	t_cmd	*cmd;

	cmd = sp->cmd_list->lst->value;
	return (cmd->redirect->lst->value);
}

void	test_redirecter_in(void)
{
	t_shell_op		*sp;
	t_redirect		*r;

	setup(&sp);
	r = get_redirect_in(sp);
	CU_ASSERT_EQUAL(r->type, IN);
	CU_ASSERT_NOT_EQUAL(r->fd, ERROR);
	CU_ASSERT_STRING_EQUAL(r->path, IN_FILE0);
	shell_op_destroy(&sp);
}
