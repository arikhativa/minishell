/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pair.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:03:53 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 15:08:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipe_pair.h"

void	pipe_pair_init_in(t_pipe_pair *pp, int fd, int fd_close)
{
	t_pipe	*p;

	p = pp->in;
	pipe_init(p, PIPE_IN, fd, fd_close);
}

void	pipe_pair_init_out(t_pipe_pair *pp, int fd, int fd_close)
{
	t_pipe	*p;

	p = pp->out;
	pipe_init(p, PIPE_OUT, fd, fd_close);
}
