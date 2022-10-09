/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax_error.t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:50:23 by yoav             ###   ########.fr       */
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
	char			*bad_str;

	bad_str = NULL;
	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(1, "|");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp, &bad_str);
	CU_ASSERT_EQUAL(err, SYNTAX_ERROR);
	CU_ASSERT_STRING_EQUAL(bad_str, "|");
	shell_op_destroy(&sp);
}

void	test_parser_open_pipe(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			*bad_str;

	bad_str = NULL;
	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(3, "pwd", "|", "\n");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp, &bad_str);
	CU_ASSERT_EQUAL(err, SYNTAX_PIPE_STILL_OPEN);
	CU_ASSERT_PTR_NULL(bad_str);
	shell_op_destroy(&sp);
}

void	test_parser_semi_redirect_error(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			*bad_str;

	bad_str = NULL;
	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(3, "cat", "<", "\n");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp, &bad_str);
	CU_ASSERT_EQUAL(err, SYNTAX_ERROR);
	CU_ASSERT_PTR_NOT_NULL_FATAL(bad_str);
	CU_ASSERT_STRING_EQUAL(bad_str, "<");
	shell_op_destroy(&sp);
}
