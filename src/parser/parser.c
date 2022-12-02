/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:25:24 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 11:57:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count(t_dll *elem, void *ret)
{
	t_token	*t;
	int		*size;

	size = ret;
	t = elem->value;
	if (PIPE == t->type)
		++(*size);
	return (SUCCESS);
}

static int	count_pipes(t_token_list *lst)
{
	int	size;

	size = 0;
	dll_iterate(lst->tok_lst, count, &size);
	return (size);
}

static t_error_code	hndl_error(t_error_code err, t_dll *node, t_shell_op *sp)
{
	t_token			*t;

	if (SYNTAX_ERROR == err)
	{
		t = (t_token *)node->value;
		error_code_print(3, PARSE_ERROR_STR, t->value, QUOTE_STR);
	}
	if (SUCCESS == err && PIPE_LIMIT <= count_pipes(sp->token_list))
	{
		error_code_print(1, PIPE_LIMIT_ERROR_STR);
		return (PIPE_LIMIT_ERROR);
	}
	return (err);
}

t_error_code	parser_check_tokens(t_shell_op *sp)
{
	t_error_code	err;
	t_dll			*node;
	int				i;

	err = SUCCESS;
	i = 0;
	node = token_list_get_node(sp->token_list);
	while (SUCCESS == err && node)
	{
		err = is_token_valid(node, &i);
		if (SYNTAX_PIPE_STILL_OPEN == err)
			sp->open_pipe = TRUE;
		if (SUCCESS == err)
			node = get_next_node(node, i);
	}
	return (hndl_error(err, node, sp));
}
