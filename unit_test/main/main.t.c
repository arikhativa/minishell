/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:59:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static FILE	*g_temp_file = NULL;

int	init_suite(void)
{
	g_temp_file = fopen(TEST_RES, "w+");
	if (NULL == g_temp_file)
		return (-1);
	return (0);
}

int	clean_suite(void)
{
	if (0 != fclose(g_temp_file))
		return (-1);
	g_temp_file = NULL;
	return (0);
}

int	main(void)
{
	if (CUE_SUCCESS != CU_initialize_registry())
		return (CU_get_error());
	CU_register_suites(g_suites);
	CU_basic_set_mode(CU_BRM_NORMAL);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (CU_get_error());
}
