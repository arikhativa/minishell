/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 11:09:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
// TODO err print
t_error_code	executer_run_cmd(t_cmd *c)
{
	int		stt;
	pid_t	pid;

	if (OK != c->stt)
	{
		printf("file not found / no acces\n");
		return (SUCCESS);
	}
	pid = fork();
	if (NEW_PROC == pid)
	{
		stt = execve(c->exec_path, c->argv, c->env);
		if (ERROR == stt)
			printf("minishell child proc err: %s\n", strerror(errno));
		return (stt);
	}
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	wait(&stt);
	return (SUCCESS);
}

t_error_code	executer_run_builtin(t_shell_op *sp, t_cmd *c)
{
	t_builtin	f;

	f = builtin_get_func(cmd_get_cmd(c));
	return (f(sp, c));
}

t_error_code	executer_run_all_cmds(t_shell_op *sp)
{
	t_error_code	err;
	t_dll			*n;

	err = SUCCESS;
	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n && SUCCESS == err)
	{
		if (is_builtin(cmd_get_cmd(n->value)))
			err = executer_run_builtin(sp, n->value);
		else
			err = executer_run_cmd(n->value);
		n = cmd_list_get_next_cmd(n);
	}
	return (err);
}
