/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter_multi.t.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/27 10:40:33 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "redirecter.h"
#include "commander.h"
#include "executer.h"
#include "laxer.h"

#define IN_FILE			"unit_test/resources/redirect_file"
#define IN_FILE_TEXT	"aaa"

static void	setup(t_shell_op **ret)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(5, "cat", "<", IN_FILE, ">", TEST_FILE);
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = redirecter_setup_files(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = executer_run_all_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	*ret = sp;
}

void	test_redirecter_multi(void)
{
	t_shell_op	*sp;
	char		b[20];
	int			fd;
	int			i;

	setup(&sp);
	if (SUCCESS == access(TEST_FILE, F_OK))
	{
		fd = open(TEST_FILE, O_RDONLY);
		CU_ASSERT_NOT_EQUAL_FATAL(fd, ERROR);
		i = read(fd, b, sizeof(b));
		CU_ASSERT_NOT_EQUAL_FATAL(i, ERROR);
		b[i] = 0;
		CU_ASSERT_STRING_EQUAL(b, IN_FILE_TEXT);
		if (SUCCESS != remove(TEST_FILE))
			CU_FAIL("file was not deleted");
	}
	shell_op_destroy(&sp);
}
