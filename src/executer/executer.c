/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/03 08:49:51 by yrabby           ###   ########.fr       */
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

t_error_code	executer_run_all_cmds(t_shell_op *sp)
{
	t_error_code	err;

	mini_signal_disable();
	if (!is_forks_in_cmd(sp))
		err = run_single_builtin(sp);
	else
		err = executer_run_many_cmds(sp);
	mini_signal_interactive_mode();
	return (err);
}
