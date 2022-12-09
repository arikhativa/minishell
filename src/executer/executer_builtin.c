/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/09 10:23:49 by yrabby           ###   ########.fr       */
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

t_error_code	run_single_builtin(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;

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
