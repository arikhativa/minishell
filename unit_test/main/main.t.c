/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 10:51:59 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static FILE	*g_temp_file = NULL;
char		**g_envp = NULL;

int	init_suite(void)
{
	g_temp_file = fopen(TEST_RES, "w+");
	if (NULL == g_temp_file)
		return (ERROR);
	return (SUCCESS);
}

int	clean_suite(void)
{
	if (SUCCESS != fclose(g_temp_file))
		return (ERROR);
	if (SUCCESS != remove(TEST_RES))
		return (ERROR);
	g_temp_file = NULL;
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;

	(void)argc;
	(void)envp;
	(void)argv;
	if (CUE_SUCCESS != CU_initialize_registry())
		return (CU_get_error());
	err = env_initenv(&g_envp, envp);
	if (SUCCESS != err)
		return (CU_get_error());
	CU_register_suites(g_suites);
	CU_basic_set_mode(CU_BRM_NORMAL);
	CU_basic_run_tests();
	CU_cleanup_registry();
	tab_deep_destroy(&g_envp);
	return (CU_get_error());
}
