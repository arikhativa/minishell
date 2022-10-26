/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:19:27 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:13:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "token_list.h"

void	test_tok_lst_create_destroy(void)
{
	t_error_code	err;
	t_token_list	*lst;
	t_token			*t;
	char			*s;

	s = "str";
	err = token_list_create(&lst);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = token_create(&t, s, WORD);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	token_list_add_last(lst, t);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst->tok_lst);
	CU_ASSERT_PTR_NOT_NULL_FATAL(lst->tok_lst->value);
	CU_ASSERT_PTR_EQUAL(t, lst->tok_lst->value);
	token_list_destroy(&lst);
	CU_ASSERT_PTR_NULL(lst);
}
