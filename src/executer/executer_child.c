/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/21 13:54:03 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

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
	stt = execve(c->exec_path, c->argv, sp->envp);
	if (ERROR == stt)
		error_code_print(3, strerror(errno), ": ", cmd_get_cmd(c));
	return (SUCCESS);
}
