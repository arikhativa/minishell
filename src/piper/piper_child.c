/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:34:51 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 11:56:35 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piper.h"

static t_error_code	dup_if_needed(t_pipe *p)
{
	if (p && p->on)
	{
		if (PIPE_IN == p->type)
			return (dup_wrapper(p->fd, STDIN_FILENO));
		else if (PIPE_OUT == p->type)
			return (dup_wrapper(p->fd, STDOUT_FILENO));
	}
	return (SUCCESS);
}

t_error_code	piper_child_dup_if_needed(t_cmd *c)
{
	t_error_code	err;

	if (!c || !c->pp)
		return (ERROR);
	err = dup_if_needed(c->pp->out);
	if (SUCCESS == err)
		err = dup_if_needed(c->pp->in);
	return (err);
}
