/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:09:33 by yoav              #+#    #+#             */
/*   Updated: 2022/10/06 09:42:06 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "tab.h"

void	test_tab_create_destroy(void)
{
	char	**tab;

	tab = util_create_tab(3, "s1", "s2", "s3");
	tab_deep_destroy(&tab);
	CU_ASSERT_PTR_NULL(tab);
}

void	test_tab_add(void)
{
	t_error_code	err;
	char			**tab;
	char			*new_str;

	new_str = ft_strdup("s4");
	CU_ASSERT_PTR_NOT_NULL(new_str);
	tab = util_create_tab(3, "s1", "s2", "s3");
	err = tab_add(&tab, new_str);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	CU_ASSERT_STRING_EQUAL(tab[3], new_str);
	CU_ASSERT_PTR_NULL(tab[4]);
	tab_deep_destroy(&tab);
	CU_ASSERT_PTR_NULL(tab);
}
