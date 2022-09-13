/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dll_tests.t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:57:23 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_dll_tests[] = {
{
	"test_dll_remove_last_elem",
	test_dll_remove_last_elem,
},
{
	"test_dll_remove_first_elem",
	test_dll_remove_first_elem,
},
{
	"test_dll_remove_elem",
	test_dll_remove_elem,
},
{
	"test_dll_get_last_elem",
	test_dll_get_last_elem,
},
{
	"test_dll_add_last",
	test_dll_add_last,
},
{
	"test_dll_add_before",
	test_dll_add_before,
},
{
	"test_dll_add_after",
	test_dll_add_after,
},
{
	"test_dll_swap_value",
	test_dll_swap_value,
},
{
	"test_dll_create_and_destroy_elem",
	test_dll_create_and_destroy_elem,
},
{
	"test_dll_clear_list",
	test_dll_clear_list,
},
	CU_TEST_INFO_NULL,
};
