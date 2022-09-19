/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_suites.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/09/17 11:50:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_SuiteInfo	g_suites[] = {
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
