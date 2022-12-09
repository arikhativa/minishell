/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/03 08:49:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

t_error_code	executer_run_builtin(t_shell_op *sp, t_cmd *c)
{
	t_builtin	f;

	f = builtin_get_func(cmd_get_cmd(c));
	if (!f)
		return (NO_BUILTIN_ERROR);
	return (f(sp, c));
}

t_error_code	run_single_builtin(t_shell_op *sp)
{
	t_error_code	err;
	t_cmd			*c;

	c = cmd_list_get_list(shell_op_get_cmd_list(sp))->value;
	if (OK != c->stt)
	{
		sp->last_cmd_stt = c->stt;
		return (SUCCESS);
	}
	redirecter_set_stream_if_needed(c);
	err = executer_run_builtin(sp, c);
	sp->last_cmd_stt = c->builtin_ret_val;
	return (err);
}

t_bool	is_forks_in_cmd(t_shell_op *sp)
{
	t_cmd_list	*lst;

	lst = shell_op_get_cmd_list(sp);
	if (1 == cmd_list_size(lst))
		return (!is_builtin(cmd_get_cmd(lst->lst->value)));
	return (TRUE);
}
