/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:09:33 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 09:24:07 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "tab.h"

void	test_tab_create_destroy(void)
{
	char			*s1;
	char			*s2;
	char			**tab;
	t_error_code	err;

	s1 = ft_strdup("s1");
	s2 = ft_strdup("s2");
	err = tab_create(&tab, 2);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	tab[0] = s1;
	tab[1] = s2;
	tab_destroy(&tab);
	CU_ASSERT_PTR_NULL(tab);
	CU_ASSERT_PTR_NULL(s1);
	CU_ASSERT_PTR_NULL(s2);
}
