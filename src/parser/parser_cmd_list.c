/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:57:51 by yoav              #+#    #+#             */
/*   Updated: 2022/09/22 17:26:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_error_code	break_logic(t_dll *n, int *skip)
{
}

static t_error_code	semi_redirect_logic(t_dll **node, int *skip)
{
}

static t_error_code	pipe_logic(t_dll *n, int *skip)
{
}
// TODO
static t_error_code	redirect_logic(t_cmd *c, t_token *t)
{
	if (redirect_util_is_input(t->type))
	{
		c->in = 
	}
}

static t_error_code	word_logic(t_cmd *c, t_token *t)
{
	t_error_code	err;

	if (NULL == c->args)
	{
		err = arg_list_create(&(c->args));
		if (SUCCESS != err)
			return (err);
	}
	return (arg_list_add_last(c->args, (char *)t->value));
}

t_error_code	parser_create_cmd(t_cmd_list *cmd_lst, t_dll *node)
{
	t_token			*t;
	t_cmd			*c;
	t_error_code	err;
	int				skip;
	
	err = cmd_create(&c);
	if (SUCCESS != err)
		return (err);
	while (node)
	{
		skip = 1;
		t = (t_token *)node->value;
		if (token_is_word(t))
			err = word_logic(c, t);
		else if (token_is_redirect(t))
			err = redirect_logic(node, &skip);
		else if (token_is_semi_redirect(t))
			err = semi_redirect_logic(node, &skip);
		else if (token_is_pipe(t))
			return (pipe_logic(node, &skip));
		else if (token_is_break(t))
			return (break_logic(node, &skip));
		node = dll_get_n_node(node, skip);
	}
	return (cmd_list_add_cmd(cmd_lst, c));
}

t_error_code	parser_create_cmd_list(t_shell_op *sp)
{
	t_dll			*node;
	t_error_code	err;
	int				i;
	t_token			*t;

	err = cmd_list_create(&(sp->cmd_list));
	if (SUCCESS != err)
		return (err);
	i = 0;
	node = token_list_get_node(sp->token_list);
	
	return (SUCCESS);
}

