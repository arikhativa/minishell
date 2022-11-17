/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pair_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:19:20 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:19:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_pair.h"

void	pipe_pair_init_in(t_pipe_pair *pp, int fd)
{
	t_pipe	*p;

	p = pp->in;
	pipe_init(p, PIPE_IN, fd);
}

void	pipe_pair_init_out(t_pipe_pair *pp, int fd)
{
	t_pipe	*p;

	p = pp->out;
	pipe_init(p, PIPE_OUT, fd);
}
