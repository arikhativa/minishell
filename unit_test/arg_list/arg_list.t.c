/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 16:31:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "arg_list.h"

void	test_arg_list_create_destroy(void)
{
	t_error_code	err;
	t_arg_list		*lst;
	char			*tab[3];

	tab[0] = "echo";
	tab[1] = "a";
	tab[2] = "b";
	err = arg_list_create(&lst);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = arg_list_add_last(lst, tab[0]);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = arg_list_add_last(lst, tab[1]);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = arg_list_add_last(lst, tab[2]);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst->lst);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst->lst->value);
	CU_ASSERT_PTR_EQUAL(tab[0], lst->lst->value);
	arg_list_destroy(&lst);
	CU_ASSERT_PTR_NULL(lst);
}
