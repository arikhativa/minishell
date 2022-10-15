/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:06 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:50:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "shell_op.h"
#include "unit_test.h"

void	test_shell_op_create_destroy_empty(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	shell_op_destroy(&sp);
	CU_ASSERT_PTR_NULL(sp);
}

void	test_shell_op_create_destroy_with_tab(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**tab;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	tab = util_create_tab(2, "123", "abd");
	shell_op_set_input(sp, tab);
	shell_op_destroy(&sp);
	CU_ASSERT_PTR_NULL(sp);
}

static void	add_tab(t_shell_op *sp)
{
	char	**tab;

	tab = util_create_tab(2, "123", "abd");
	shell_op_set_input(sp, tab);
}

void	test_shell_op_create_destroy_with_token_list(void)
{
	t_error_code	err;
	t_shell_op		*sp;
	t_token_list	*tok_lst;
	t_token			*tok;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	add_tab(sp);
	err = token_list_create(&tok_lst);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	shell_op_set_token_list(sp, tok_lst);
	err = token_create(&tok, sp->input[0], WORD);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = token_list_add_last(tok_lst, tok);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = token_create(&tok, sp->input[1], WORD);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	err = token_list_add_last(tok_lst, tok);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	shell_op_destroy(&sp);
	CU_ASSERT_PTR_NULL(sp);
}
