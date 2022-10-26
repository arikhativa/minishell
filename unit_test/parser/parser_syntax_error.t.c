/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax_error.t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 14:02:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laxer.h"
#include "unit_test_util.h"
#include "unit_test.h"
#include "parser.h"

void	test_parser_bad_first_tok(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(1, "|");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp);
	CU_ASSERT_EQUAL(err, SYNTAX_ERROR);
	shell_op_destroy(&sp);
}

void	test_parser_open_pipe(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(2, "pwd", "|");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp);
	CU_ASSERT_EQUAL(err, SYNTAX_PIPE_STILL_OPEN);
	shell_op_destroy(&sp);
}

void	test_parser_redirect_error(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(2, "cat", "<");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp);
	CU_ASSERT_EQUAL(err, SYNTAX_ERROR);
	shell_op_destroy(&sp);
}
