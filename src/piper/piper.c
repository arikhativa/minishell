/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:34:51 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 16:41:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piper.h"

static int	init_pipes(t_dll *n, void *param)
{
	int				p[2];
	t_error_code	err;

	(void)param;
	if (is_one_cmd(n))
		return (SUCCESS);
	if (is_first_cmd(n))
		return (SUCCESS);
	err = pipe(p);
	if (SUCCESS != err)
		return (err);
	cmd_set_pipe_out(n->prev->value, p[PIPE_WRITE], p[PIPE_READ]);
	cmd_set_pipe_in(n->value, p[PIPE_READ], p[PIPE_WRITE]);
	return (SUCCESS);
}

static int	close_pipes(t_dll *n, void *param)
{
	t_cmd	*c;

	(void)param;
	if (!n || !n->value)
		return (SUCCESS);
	c = n->value;
	return (pipe_pair_close(c->pp));
}

t_error_code	piper_init_pipes(t_shell_op *sp)
{
	return(cmd_list_iter(shell_op_get_cmd_list(sp), init_pipes, NULL));
}

t_error_code	piper_close_pipes(t_shell_op *sp)
{
	t_error_code	err;
	t_cmd_list		*l;

	l = shell_op_get_cmd_list(sp);
	if (!l)
		return (SUCCESS);
	err = cmd_list_iter(l, close_pipes, NULL);
	if (SUCCESS != err)
		error_code_print_internal_err(err);
	return (err);
}
