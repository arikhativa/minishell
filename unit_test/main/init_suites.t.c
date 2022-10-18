/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_suites.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/10/15 21:49:16 by alopez-g         ###   ########.fr       */
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
	"executer",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_executer_tests,
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
	"reader",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_reader_tests,
},
{
	"env",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_env_tests,
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
	"commander",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_commander_tests,
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
