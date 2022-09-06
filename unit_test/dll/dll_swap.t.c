/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_swap.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/06 14:40:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "dll.h"
#include "unit_test.h"

// the test func
void test_dll_swap_value(void)
{
	int		a;
	int		b;
	t_dll	e1;
	t_dll	e2;

	a = 2;
	b = 55;
	e1.value = &a;
	e2.value = &b;
	if (NULL != temp_file)
	{
		dll_swap_value(&e1, &e2);
		CU_ASSERT(*(int *)(e1.value) == 55);
		CU_ASSERT(*(int *)(e2.value) == 2);
	}
}

// configuration part
int	init_suite(void)
{
	if (NULL == (temp_file = fopen(TEST_RES, "w+")))
		return -1;
	return 0;
}

int	clean_suite(void)
{
	if (0 != fclose(temp_file))
		return -1;
	temp_file = NULL;
	return 0;
}


int	main(void)
{
	CU_pSuite pSuite;

	pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	pSuite = CU_add_suite(DEFAULT_SUITE, init_suite, clean_suite);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(pSuite, "test_dll_swap_value", test_dll_swap_value)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	CU_basic_set_mode(CU_BRM_NORMAL);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}