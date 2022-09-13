/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:55:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void	test_dll_create_and_destroy_elem(void)
{
	int		i;
	t_dll	*node;

	i = 6;
	node = dll_create_elem(&i);
	CU_ASSERT_PTR_NOT_NULL(node);
	CU_ASSERT(*(int *)(node->value) == 6);
	dll_destroy_elem(node);
}

void	test_dll_clear_list(void)
{
	int		i;
	t_dll	*lst;

	i = 1;
	lst = NULL;
	dll_add_last(&lst, dll_create_elem(&i));
	dll_add_last(&lst, dll_create_elem(&i));
	dll_add_last(&lst, dll_create_elem(&i));
	dll_clear_list(lst, NULL);
}
