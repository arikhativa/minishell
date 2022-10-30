/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:45:35 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 16:39:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	cmd_set_pipe_in(t_cmd *c, int fd, int fd_close)
{
	pipe_pair_init_in(c->pp, fd, fd_close);
}

void	cmd_set_pipe_out(t_cmd *c, int fd, int fd_close)
{
	pipe_pair_init_out(c->pp, fd, fd_close);
}
