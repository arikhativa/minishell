/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_op_tests.t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 09:52:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_shell_op_tests[] = {
{
	"test_shell_op_create_destroy_empty",
	test_shell_op_create_destroy_empty,
},
{
	"test_shell_op_create_destroy_with_tab",
	test_shell_op_create_destroy_with_tab,
},
{
	"test_shell_op_create_destroy_with_token_list",
	test_shell_op_create_destroy_with_token_list,
},
	CU_TEST_INFO_NULL,
};
