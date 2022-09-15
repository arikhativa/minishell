/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:09:33 by yoav              #+#    #+#             */
/*   Updated: 2022/09/15 17:38:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "tab.h"

void	test_tab_create_destroy(void)
{
	char			**tab;
	t_error_code	err;

	err = tab_create(&tab, 3);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	tab[0] = ft_strdup("s1");
	tab[1] = ft_strdup("s2");
	tab[2] = ft_strdup("s3");
	tab_destroy(&tab);
	CU_ASSERT_PTR_NULL(tab);
}
