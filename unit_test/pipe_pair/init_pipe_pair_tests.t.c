/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe_pair_tests.t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:21:24 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:21:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_pipe_pair_tests[] = {
{
	"test_pipe_pair_create_destroy",
	test_pipe_pair_create_destroy,
},
{
	"test_pipe_pair_open_close",
	test_pipe_pair_open_close,
},
	CU_TEST_INFO_NULL,
};
