/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:45:24 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 10:49:35 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

static int	add_envp(t_dll *elem, void *envp)
{
	t_cmd	*c;

	c = elem->value;
	c->env = envp;
	return (SUCCESS);
}

t_error_code	iter_all_cmds(t_shell_op *sp)
{
	char			**path_tab;
	t_error_code	err;

	err = dll_iterate(sp->cmd_list->lst, add_envp, sp->envp);
	if (SUCCESS != err)
		return (err);
	err = get_path_tab(&path_tab, sp->envp);
	if (SUCCESS != err)
		return (err);
	err = dll_iterate(sp->cmd_list->lst, commander_init_exec_path, path_tab);
	if (SUCCESS != err)
		return (err);
	tab_deep_destroy(&path_tab);
	return (SUCCESS);
}
