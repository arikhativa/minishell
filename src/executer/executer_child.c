/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/29 12:54:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

t_error_code	executer_run_builtin(t_shell_op *sp, t_cmd *c)
{
	t_builtin	f;

	if (OK != c->stt)
		return (SUCCESS);
	f = builtin_get_func(cmd_get_cmd(c));
	if (!f)
		return (NO_BUILTIN_ERROR);
	return (f(sp, c));
}

// TODO do something with stt = execve() on err
// TODO err print
t_error_code	executer_child_logic(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;
	int				stt;

	err = piper_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	err = piper_close_pipes(sp);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	err = redirecter_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	if (is_builtin(cmd_get_cmd(c)))
	{
		err = executer_run_builtin(sp, c);
		return (error_code_print_internal_err(err));
	}
	else
	{
		stt = execve(c->exec_path, c->argv, sp->envp);
		if (ERROR == stt)
			error_code_print(3, strerror(errno), ": ", cmd_get_cmd(c));
	}
	return (SUCCESS);
}
