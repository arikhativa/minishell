/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:45:24 by yoav              #+#    #+#             */
/*   Updated: 2022/10/24 10:25:20 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

t_error_code	iter_all_cmds(t_shell_op *sp)
{
	char			**path_tab;
	t_error_code	err;

	err = get_path_tab(&path_tab, sp->envp);
	if (SUCCESS != err)
		return (err);
	err = dll_iterate(sp->cmd_list->lst, commander_init_exec_path, path_tab);
	if (SUCCESS != err)
		return (err);
	tab_deep_destroy(&path_tab);
	return (SUCCESS);
}
