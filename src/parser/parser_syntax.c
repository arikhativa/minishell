/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:54:10 by yoav              #+#    #+#             */
/*   Updated: 2022/09/21 13:06:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_error_code	break_logic(t_dll *n, int *skip)
{
	t_token			*t;

	n = n->next;
	if (n)
	{
		t = (t_token *)(n->value);
		if (PIPE == t->type)
			return (SYNTAX_ERROR);
	}
	++(*skip);
	return (SUCCESS);
}

static t_error_code	semi_redirect_logic(t_dll **node, int *skip)
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
		return (SYNTAX_PIPE_STILL_OPEN);
	t = (t_token *)(n->value);
	if (NEW_LINE == t->type || SEMICOLON == t->type)
		return (SYNTAX_PIPE_STILL_OPEN);
	++(*skip);
	return (SUCCESS);
}

t_error_code	is_token_valid(t_dll *node, int *skip)
{
	t_error_code	err;
	t_token			*t;

	t = (t_token *)node->value;
	if (PIPE == t->type)
		return (SYNTAX_ERROR);
	*skip = 0;
	err = SUCCESS;
	while (node && SUCCESS == err)
	{
		t = (t_token *)node->value;
		if (WORD == t->type || REDIRECT == t->type)
		{
			node = node->next;
			++(*skip);
		}
		else if (SEMI_REDIRECT == t->type)
			err = semi_redirect_logic(&node, skip);
		else if (PIPE == t->type)
			return (pipe_logic(node, skip));
		else if (SEMICOLON == t->type || NEW_LINE == t->type)
			return (break_logic(node, skip));
	}
	return (err);
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
