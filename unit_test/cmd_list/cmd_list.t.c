/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 12:27:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "unit_test_util.h"
#include "cmd_list.h"

static void	internal_create_cmd(t_cmd **c, char *s)
{
	t_error_code	err;

	err = cmd_create(c);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = cmd_add_arg(*c, s);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
}

static void	internal_create_cmd_list(t_cmd_list **lst)
{
	t_error_code	err;
	t_cmd			*c1;
	t_cmd			*c2;

	err = cmd_list_create(lst);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	internal_create_cmd(&c1, "word1");
	internal_create_cmd(&c2, "word2");
	err = cmd_list_add_cmd(*lst, c1);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = cmd_list_add_cmd(*lst, c2);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
}

void	test_cmd_list_create_destroy(void)
{
	t_cmd_list		*lst;
	t_cmd			*c;
	char			*arg;

	internal_create_cmd_list(&lst);
	c = (t_cmd *)lst->lst->value;
	arg = cmd_get_cmd(c);
	CU_ASSERT_PTR_NOT_NULL_FATAL(arg);
	CU_ASSERT_STRING_EQUAL(arg, "word1");
	c = (t_cmd *)lst->lst->next->value;
	arg = cmd_get_cmd(c);
	CU_ASSERT_PTR_NOT_NULL_FATAL(arg);
	CU_ASSERT_STRING_EQUAL(arg, "word2");
	cmd_list_destroy(&lst);
	CU_ASSERT_PTR_NULL(lst);
}
