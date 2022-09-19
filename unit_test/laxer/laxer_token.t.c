/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer_token.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 12:02:23 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "laxer.h"

static void	add_to_tab(char **tab, int i, char *s)
{
	tab[i] = ft_strdup(s);
	CU_ASSERT_PTR_NOT_NULL_FATAL(tab[0]);
}

static char	**tab_create_and_init(void)
{
	char			**tab;
	t_error_code	err;

	err = tab_create(&tab, 15);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	add_to_tab(tab, 0, "cat");
	add_to_tab(tab, 1, "<<");
	add_to_tab(tab, 2, ">>");
	add_to_tab(tab, 3, "|");
	add_to_tab(tab, 4, ">file");
	add_to_tab(tab, 5, "<file");
	add_to_tab(tab, 6, "1<");
	add_to_tab(tab, 7, "2<");
	add_to_tab(tab, 8, "a2<");
	add_to_tab(tab, 9, "0<file");
	add_to_tab(tab, 10, ";");
	add_to_tab(tab, 11, "\n");
	add_to_tab(tab, 12, "0<<str");
	add_to_tab(tab, 13, "2>>file");
	add_to_tab(tab, 14, "0<<");
	return (tab);
}

static void	ttt(t_dll *lst)
{
	static t_token_type	arr[] = {WORD, SEMI_REDIRECT, SEMI_REDIRECT, PIPE, \
		REDIRECT, REDIRECT, SEMI_REDIRECT, SEMI_REDIRECT, WORD, REDIRECT, \
		SEMICOLON, NEW_LINE, REDIRECT, REDIRECT, SEMI_REDIRECT};
	int					i;
	t_token				*t;

	i = 0;
	while (lst)
	{
		t = (t_token *)lst->value;
		CU_ASSERT_EQUAL(t->type, arr[i]);
		lst = lst->next;
		++i;
	}
}

void	test_laxer_check_all_tokens(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = tab_create_and_init();
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	ttt(sp->token_list->tok_lst);
	shell_op_destroy(&sp);
}
