/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_laxer_tests.t.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 11:20:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_laxer_tests[] = {
{
	"test_laxer_check_all_tokens",
	test_laxer_check_all_tokens,
},
{
	"test_laxer_create_destroy",
	test_laxer_create_destroy,
},
	CU_TEST_INFO_NULL,
};
