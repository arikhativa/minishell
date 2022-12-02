/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 16:49:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	hndl_child_signal_exit(int *ret, int sig)
{
	if (SIGINT == sig)
	{
		*ret = CMD_EXIT_SIG_INT;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else if (SIGQUIT == sig)
	{
		*ret = CMD_EXIT_SIG_QUIT;
		ft_putstr_fd(SIGQUIT_STR, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

static void	builtin_logic(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;

	err = executer_run_builtin(sp, c);
	if (SUCCESS != err)
		error_code_print_internal_err(err);
	shell_op_destroy(&sp);
	exit(err);
}

// TODO do something with stt = execve() on err
// TODO err print
void	executer_child_logic(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;
	int				stt;

	err = mini_signal_set_child();
	if (SUCCESS != err)
		exit(error_code_print_internal_err(err));
	err = piper_child_dup_if_needed(c);
	if (SUCCESS != err)
		exit(error_code_print_internal_err(err));
	err = piper_close_pipes(sp);
	if (SUCCESS != err)
		exit(error_code_print_internal_err(err));
	err = redirecter_child_dup_if_needed(c);
	if (SUCCESS != err)
		exit(error_code_print_internal_err(err));
	if (is_builtin(cmd_get_cmd(c)))
		builtin_logic(sp, c);
	stt = execve(c->exec_path, c->argv, sp->envp);
	if (ERROR == stt)
		error_code_print(3, strerror(errno), ": ", cmd_get_cmd(c));
	exit(stt);
}
