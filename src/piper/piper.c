/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:34:51 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:10:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piper.h"

static int	init_pipes(t_dll *n, void *shell_op)
{
	int				p[2];
	t_error_code	err;
	t_shell_op		*sp;

	sp = shell_op;
	if (is_one_cmd(n))
		return (SUCCESS);
	if (is_first_cmd(n))
		return (SUCCESS);
	err = pipe(p);
	if (SUCCESS != err)
		return (err);
	err = pipe_list_add(sp->pipe_list, p);
	if (SUCCESS != err)
		return (err);
	cmd_set_pipe_out(n->prev->value, p[PIPE_WRITE]);
	cmd_set_pipe_in(n->value, p[PIPE_READ]);
	return (SUCCESS);
}

t_error_code	piper_init_pipes(t_shell_op *sp)
{
	return (cmd_list_iter(shell_op_get_cmd_list(sp), init_pipes, sp));
}

t_error_code	piper_close_pipes(t_shell_op *sp)
{
	if (!sp->pipe_list)
		return (SUCCESS);
	return (pipe_list_close(sp->pipe_list));
}
