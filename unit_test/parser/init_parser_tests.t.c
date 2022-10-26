/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_tests.t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:13:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_parser_tests[] = {
{
	"test_parser_redirect_error",
	test_parser_redirect_error,
},
{
	"test_parser_open_pipe",
	test_parser_open_pipe,
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
