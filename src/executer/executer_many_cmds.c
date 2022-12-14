/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_many_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:08:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	hndl_last_cmd(t_shell_op *sp, t_dll *n)
{
	int		stt;
	t_cmd	*c;

	c = n->value;
	if (OK != c->stt)
		sp->last_cmd_stt = c->stt;
	else
	{
		waitpid(c->pid, &stt, 0);
		if (WIFEXITED(stt))
		{
			if (is_builtin(cmd_get_cmd(c)))
				sp->last_cmd_stt = c->builtin_ret_val;
			else
				sp->last_cmd_stt = WEXITSTATUS(stt);
		}
		else if (WIFSIGNALED(stt))
			hndl_child_signal_exit(&(sp->last_cmd_stt), stt);
	}
}

static void	wait_all_cmds(t_shell_op *sp)
{
	int		stt;
	t_dll	*n;
	t_cmd	*c;

	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n->next)
	{
		c = n->value;
		if (OK == c->stt)
			waitpid(c->pid, &stt, 0);
		n = cmd_list_get_next_cmd(n);
	}
	hndl_last_cmd(sp, n);
}

t_error_code	executer_run_many_cmds(t_shell_op *sp)
{
	t_error_code	err;
	t_dll			*n;

	err = SUCCESS;
	n = cmd_list_get_list(shell_op_get_cmd_list(sp));
	while (n && SUCCESS == err)
	{
		err = executer_run_cmd(sp, n->value);
		n = cmd_list_get_next_cmd(n);
	}
	if (SUCCESS != err)
		return (err);
	piper_close_pipes(sp);
	wait_all_cmds(sp);
	return (err);
}
