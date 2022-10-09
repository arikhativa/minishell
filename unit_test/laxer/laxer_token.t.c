/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer_token.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:50:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "unit_test_util.h"
#include "laxer.h"

static void	assert_tokens(t_dll *lst)
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

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	sp->input = util_create_tab(15, "cat", "<<", ">>", "|", ">file", "<file", \
		"1<", "2<", "a2<", "0<file", ";", "\n", "0<<str", "2>>file", "0<<");
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	assert_tokens(sp->token_list->tok_lst);
	shell_op_destroy(&sp);
}
