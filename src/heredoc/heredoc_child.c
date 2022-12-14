/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/14 16:08:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	child_signal_exit(int sig)
{
	t_shell_op	*sp;

	sp = shell_op_get_sp(NULL);
	if (SIGINT == sig)
	{
		sp->last_cmd_stt = BUILTIN_RET_VAL_ERROR;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

t_error_code	heredoc_run_child(t_redirect *r)
{
	int		stt;
	pid_t	pid;

	mini_signal_disable();
	pid = fork();
	if (NEW_PROC == pid)
	{
		mini_signal_set_heredoc();
		heredoc_handle_heredoc(r);
		exit(SUCCESS);
	}
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	waitpid(pid, &stt, 0);
	mini_signal_interactive_mode();
	if (WIFSIGNALED(stt))
	{
		child_signal_exit(stt);
		return (HEREDOC_SIGNAL_EXIT);
	}
	return (SUCCESS);
}
