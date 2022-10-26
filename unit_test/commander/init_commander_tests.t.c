/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commander_tests.t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:25:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_commander_tests[] = {
{
	"test_commander_redirect",
	test_commander_redirect,
},
{
	"test_commander",
	test_commander,
},
{
	"test_path_var_search",
	test_path_var_search,
},
	CU_TEST_INFO_NULL,
};
