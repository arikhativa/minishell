/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:25:24 by yoav              #+#    #+#             */
/*   Updated: 2022/09/21 13:05:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error_code	parser_check_tokens(t_shell_op *sp, char **bad_str)
{
	t_error_code	err;
	t_dll			*node;
	t_token			*t;
	int				i;

	err = SUCCESS;
	i = 0;
	node = token_list_get_node(sp->token_list);
	while (SUCCESS == err && node)
	{
		err = is_token_valid(node, &i);
		node = get_next_node(node, i);
	}
	if (SYNTAX_ERROR == err)
	{
		t = (t_token *)node->value;
		*bad_str = t->value;
	}
	return (err);
}
