/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirecter_tests.t.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/30 12:36:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_redirecter_tests[] = {
{
	"test_redirecter_in",
	test_redirecter_in,
},
{
	"test_redirecter_append",
	test_redirecter_append,
},
{
	"test_redirecter_no_cmd",
	test_redirecter_no_cmd,
},
{
	"test_redirecter_multi",
	test_redirecter_multi,
},
{
	"test_redirecter_out",
	test_redirecter_out,
},
	CU_TEST_INFO_NULL,
};
