/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_valid_pipe_limit.t.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 11:52:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "laxer.h"
#include "unit_test.h"
#include "parser.h"

void	test_parser_pipe_limit(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(145, "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a", "|", \
		"a", "|", "a", "|", "a", "|", "a", "|", "a", "|", "a");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	CU_ASSERT_EQUAL(err, SUCCESS);
	err = parser_check_tokens(sp);
	CU_ASSERT_EQUAL(err, PIPE_LIMIT_ERROR);
	shell_op_destroy(&sp);
}
