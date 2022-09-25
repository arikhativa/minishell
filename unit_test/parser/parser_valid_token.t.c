/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/09/21 13:02:18 by yoav             ###   ########.fr       */
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
	char			*bad_str;

	bad_str = NULL;
	err = shell_op_create(&sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(7, "cat", "file", "|", "grep", "a", "1>file2", \
		"\n");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = parser_check_tokens(sp, &bad_str);
	CU_ASSERT_EQUAL(err, SUCCESS);
	CU_ASSERT_PTR_NULL(bad_str);
	shell_op_destroy(&sp);
}
