/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/06 10:59:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
t_error_code	executer_run_cmd(t_cmd *c)
{
	int		stt;
	pid_t	pid;

	pid = fork();
	if (NEW_PROC == pid)
	{
		stt = execve(c->argv[0], c->argv, c->env);
		if (ERROR == stt)
			printf("%s\n", strerror(errno));
	}
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	wait(&pid);
	return (SUCCESS);
}

// TODO make this better
t_error_code	executer_run_cmd_list(t_shell_op *sp)
{
	t_dll	*node = sp->cmd_list->lst;

	// cmd_list_get_next_cmd(shell_op_get_cmd_list(sp));
	while (node)
	{
		executer_run_cmd((t_cmd *)node->value);
		node = node->next;
	}
	return (SUCCESS);
}

