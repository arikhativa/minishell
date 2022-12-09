/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/08 16:08:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
// TODO err print
t_error_code	executer_run_cmd(t_shell_op *sp, t_cmd *c)
{
	pid_t	pid;

	if (OK != c->stt)
		return (SUCCESS);
	pid = fork();
	if (NEW_PROC == pid)
		executer_child_logic(sp, c);
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	c->pid = pid;
	return (SUCCESS);
}

static t_bool	is_forks_in_cmd(t_shell_op *sp)
{
	t_cmd_list	*lst;

	lst = shell_op_get_cmd_list(sp);
	if (1 == cmd_list_size(lst))
		return (!is_builtin(cmd_get_cmd(lst->lst->value)));
	return (TRUE);
}

// TODO make sure all builtins return "builtin_ret_val"
void	wait_all_cmds(t_shell_op *sp)
{
	int		stt;
	t_dll	*n;
	t_cmd	*c;

	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n)
	{
		c = n->value;
		if (OK != c->stt)
			sp->last_cmd_stt = (unsigned char)c->stt;
		else
		{
			waitpid(c->pid, &stt, 0);
			if (WIFEXITED(stt))
			{
				if (is_builtin(cmd_get_cmd(c)))
					sp->last_cmd_stt = c->builtin_ret_val;
				else
					sp->last_cmd_stt = (unsigned char)WEXITSTATUS(stt);
			}
			else if (WIFSIGNALED(stt))
				hndl_child_signal_exit(&(sp->last_cmd_stt), stt);
		}
		n = cmd_list_get_next_cmd(n);
	}
}

t_error_code	executer_run_all_cmds(t_shell_op *sp)
{
	t_error_code	err;
	t_dll			*n;

	err = SUCCESS;
	mini_signal_disable();
	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	if (!is_forks_in_cmd(sp))
		return (run_single_builtin(sp, n->value));
	while (n && SUCCESS == err)
	{
		err = executer_run_cmd(sp, n->value);
		n = cmd_list_get_next_cmd(n);
	}
	if (SUCCESS != err)
		return (err);
	piper_close_pipes(sp);
	wait_all_cmds(sp);
	mini_signal_interactive_mode();
	return (err);
}
