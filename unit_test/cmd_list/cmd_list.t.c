/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/21 13:07:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "cmd_list.h"

static void	internal_create_cmd(t_cmd **c, int ac, char **av)
{
	t_error_code	err;
	int				i;

	err = cmd_create(c);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	i = 0;
	while (i < ac)
	{
		err = cmd_add_arg(*c, av[i]);
		CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
		++i;
	}
}

static void	internal_create_cmd_list(t_cmd_list **lst)
{
	t_error_code	err;
	t_cmd			*c1;
	t_cmd			*c2;
	static char		*tab1[] = {"echo", "a", "b"};
	static char		*tab2[] = {"cat", "file", "-e"};

	err = cmd_list_create(lst);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	internal_create_cmd(&c1, 3, tab1);
	internal_create_cmd(&c2, 3, tab2);
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
	arg = (char *)c->args->lst->value;
	CU_ASSERT_STRING_EQUAL(arg, "echo");
	c = (t_cmd *)lst->lst->next->value;
	arg = (char *)c->args->lst->next->value;
	CU_ASSERT_STRING_EQUAL(arg, "file");
	cmd_list_destroy(&lst);
	CU_ASSERT_PTR_NULL(lst);
}
