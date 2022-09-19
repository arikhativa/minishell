/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_suites.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/09/19 16:22:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_SuiteInfo	g_suites[] = {
{
	"parser",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_parser_tests,
},
{
	"cmd_list",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_cmd_list_tests,
},
{
	"arg_list",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_arg_list_tests,
},
{
	"laxer",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_laxer_tests,
},
{
	"shell_op",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_shell_op_tests,
},
{
	"tab",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_tab_tests,
},
{
	"token_list",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_token_list_tests,
},
{
	"token",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_token_tests,
},
{
	"dll",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_dll_tests,
},
	CU_SUITE_INFO_NULL,
};
