/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 09:55:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

static t_error_code	commander_init_cmd(t_dll **node, t_cmd *c)
{
	t_dll			*n;
	t_token			*t;
	t_error_code	err;

	err = SUCCESS;
	n = *node;
	t = token_list_get_token(n);
	while (SUCCESS == err && t && n && is_cmd(n))
	{
		if (WORD == t->type)
			err = cmd_add_arg(c, t->value);
		n = n->next;
		t = token_list_get_token(n);
	}
	*node = n;
	return (err);
}

static t_error_code	commander_init_all_cmds(t_cmd_list *cmd_lst, \
	t_token_list *tok_lst)
{
	t_error_code	err;
	t_dll			*n;
	t_cmd			*c;

	n = commander_skip_to_next_cmd(token_list_get_node(tok_lst));
	while (n)
	{
		err = cmd_create(&c);
		if (SUCCESS != err)
			return (err);
		err = commander_init_cmd(&n, c);
		if (SUCCESS != err)
			return (err);
		err = cmd_list_add_cmd(cmd_lst, c);
		if (SUCCESS != err)
			return (err);
		n = commander_skip_to_next_cmd(n);
	}
	return (err);
}

t_error_code	commander_create_cmds(t_shell_op *sp)
{
	t_error_code	err;

	err = cmd_list_create(&(sp->cmd_list));
	if (SUCCESS != err)
		return (err);
	err = commander_init_all_cmds(sp->cmd_list, sp->token_list);
	if (SUCCESS != err)
	{
		cmd_list_destroy(&(sp->cmd_list));
		return (err);
	}
	err = iter_all_cmds(sp);
	if (SUCCESS != err)
	{
		cmd_list_destroy(&(sp->cmd_list));
		return (err);
	}
	return (err);
}
