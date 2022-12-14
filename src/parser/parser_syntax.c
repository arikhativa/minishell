/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:54:10 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:14:03 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_error_code	redirect_logic(t_dll **node, int *skip)
{
	t_dll	*n;
	t_token	*t;

	n = (*node)->next;
	if (!n)
		return (SYNTAX_ERROR);
	t = (t_token *)(n->value);
	if (WORD != t->type)
		return (SYNTAX_ERROR);
	*node = n->next;
	*skip += 2;
	return (SUCCESS);
}

static t_error_code	pipe_logic(t_dll *n, int *skip)
{
	t_token	*t;

	n = n->next;
	if (!n)
		return (SYNTAX_ERROR);
	++(*skip);
	t = (t_token *)(n->value);
	if (PIPE == t->type)
		return (SYNTAX_ERROR);
	return (SUCCESS);
}

static t_error_code	word_logic(t_dll *n, int *skip)
{
	t_token	*t;

	if (n)
		t = (t_token *)n->value;
	while (n && WORD == t->type)
	{
		n = n->next;
		if (n)
			t = (t_token *)n->value;
		++(*skip);
	}
	return (SUCCESS);
}

t_error_code	is_token_valid(t_dll *node, int *skip)
{
	t_token	*t;

	t = (t_token *)node->value;
	if (dll_is_first_elem(node) && PIPE == t->type)
		return (SYNTAX_ERROR);
	*skip = 0;
	if (WORD == t->type)
		return (word_logic(node, skip));
	else if (REDIRECT == t->type)
		return (redirect_logic(&node, skip));
	else if (PIPE == t->type)
		return (pipe_logic(node, skip));
	return (SUCCESS);
}

t_dll	*get_next_node(t_dll *node, int i)
{
	while (i)
	{
		node = node->next;
		--i;
	}
	return (node);
}
