/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get.t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:17:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:52:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void	test_dll_get_last_elem(void)
{
	int		i1;
	int		i2;
	int		i3;
	t_dll	*lst;
	t_dll	*node;

	i1 = 1;
	i2 = 2;
	i3 = 3;
	lst = NULL;
	node = NULL;
	dll_add_last(&lst, dll_create_elem(&i1));
	dll_add_last(&lst, dll_create_elem(&i2));
	dll_add_last(&lst, dll_create_elem(&i3));
	node = dll_get_last_elem(lst);
	CU_ASSERT_EQUAL(*(int *)node->value, 3);
	dll_clear_list(lst, NULL);
}
