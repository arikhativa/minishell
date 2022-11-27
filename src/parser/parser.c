/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:25:24 by yoav              #+#    #+#             */
/*   Updated: 2022/11/21 11:38:52 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error_code	parser_check_tokens(t_shell_op *sp)
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
		if (SUCCESS == err)
			node = get_next_node(node, i);
	}
	if (SYNTAX_ERROR == err)
	{
		t = (t_token *)node->value;
		error_code_print(3, PARSE_ERROR_STR, t->value, QUOTE_STR);
	}
	return (err);
}
