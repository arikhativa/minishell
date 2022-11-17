/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:03:53 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:21:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

t_error_code	pipe_create(t_pipe **ret)
{
	t_pipe	*p;

	p = ft_calloc(1, sizeof(t_pipe));
	if (!p)
		return (ALLOCATION_ERROR);
	*ret = p;
	return (SUCCESS);
}

void	pipe_destroy(t_pipe **obj)
{
	t_pipe	*p;

	p = *obj;
	ft_bzero(p, sizeof(t_pipe));
	free(p);
	*obj = NULL;
}

void	pipe_init(t_pipe *p, t_pipe_type t, int fd)
{
	p->on = TRUE;
	p->type = t;
	p->fd = fd;
}

t_error_code	pipe_close(t_pipe *p)
{
	if (p->on)
	{
		p->on = FALSE;
		return (close(p->fd));
	}
	return (SUCCESS);
}
