/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/24 10:26:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
// TODO err print
t_error_code	executer_run_cmd(t_cmd *c, char **env)
{
	int		stt;
	pid_t	pid;

	if (OK != c->stt)
	{
		if (CMD_NOT_FOUND == c->stt)
			error_code_print(2, EXEC_CMD_NOT_FOUND_STR, c->argv[0]);
		else
			error_code_print(2, EXEC_PREM_ERR_STR, c->argv[0]);
		return (SUCCESS);
	}
	pid = fork();
	if (NEW_PROC == pid)
	{
		stt = execve(c->exec_path, c->argv, env);
		if (ERROR == stt)
			error_code_print(3, strerror(errno), ": ", c->argv[0]);
		return (SUCCESS);
	}
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	c->pid = pid;
	return (SUCCESS);
}

t_error_code	executer_run_builtin(t_shell_op *sp, t_cmd *c)
{
	t_builtin	f;

	f = builtin_get_func(cmd_get_cmd(c));
	if (!f)
		return (NO_BUILTIN_ERROR);
	return (f(sp, c));
}

void	wait_all_cmds(t_shell_op *sp)
{
	int		stt;
	t_dll	*n;
	t_cmd	*c;

	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n)
	{
		c = n->value;
		if (is_builtin(cmd_get_cmd(c)))
			stt = c->builtin_ret_val;
		else if (OK != c->stt)
			stt = ERROR;
		else
			waitpid(c->pid, &stt, 0);
		sp->last_cmd_stt = stt;
		n = cmd_list_get_next_cmd(n);
	}
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
			err = executer_run_cmd(n->value, sp->envp);
		n = cmd_list_get_next_cmd(n);
	}
	wait_all_cmds(sp);
	return (err);
}
