/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_tests.t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:29:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_parser_tests[] = {
{
	"test_parser_pipe_limit",
	test_parser_pipe_limit,
},
{
	"test_parser_redirect_error",
	test_parser_redirect_error,
},
{
	"test_parser_token_check",
	test_parser_token_check,
},
{
	"test_parser_bad_first_tok",
	test_parser_bad_first_tok,
},
	CU_TEST_INFO_NULL,
};
