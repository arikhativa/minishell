/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_valid_token.t.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 14:02:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "laxer.h"
#include "unit_test.h"
#include "parser.h"

void	test_parser_token_check(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(7, "cat", "f", "|", "grep", "a", ">", "f");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	CU_ASSERT_EQUAL(err, SUCCESS);
	shell_op_destroy(&sp);
}
