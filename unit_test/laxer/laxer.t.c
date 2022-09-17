/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer.t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 12:02:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "laxer.h"

static char	**tab_create_and_init(void)
{
	char			**tab;
	t_error_code	err;

	err = tab_create(&tab, 5);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	tab[0] = ft_strdup("cat");
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[0]);
	tab[1] = ft_strdup("file");
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[1]);
	tab[2] = ft_strdup("|");
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[2]);
	tab[3] = ft_strdup("echo");
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[3]);
	tab[4] = ft_strdup("1>file2");
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[4]);
	return (tab);
}

void	test_laxer_create_destroy(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = tab_create_and_init();
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	shell_op_destroy(&sp);
}
