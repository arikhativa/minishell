/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:09:33 by yoav              #+#    #+#             */
/*   Updated: 2022/09/20 10:43:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "tab.h"

void	test_tab_create_destroy(void)
{
	char	**tab;

	tab = util_create_tab(3, "s1", "s2", "s3");
	tab_destroy(&tab);
	CU_ASSERT_PTR_NULL(tab);
}
