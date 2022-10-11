/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/11 13:12:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO replace with builtin class
t_bool	executer_handle_exit(t_shell_op *sp, t_cmd *c)
{
	if (!ft_strcmp(c->argv[0], "exit"))
	{
		sp->run = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

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

t_error_code	executer_run_all_cmds(t_shell_op *sp)
{
	t_error_code	err;
	t_dll			*n;

	err = SUCCESS;
	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n && SUCCESS == err)
	{
		if (!executer_handle_exit(sp, n->value))
			err = executer_run_cmd(n->value);
		n = cmd_list_get_next_cmd(n);
	}
	return (err);
}

