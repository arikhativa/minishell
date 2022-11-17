/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pair.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:57:44 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 14:14:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_PAIR_H
# define PIPE_PAIR_H

# include "error_code.h"
# include "pipe.h"
# include "macro.h"

typedef struct s_pipe_pair
{
	t_pipe	*in;
	t_pipe	*out;
}	t_pipe_pair;

t_error_code	pipe_pair_create(t_pipe_pair **ret);
void			pipe_pair_destroy(t_pipe_pair **obj);
t_error_code	pipe_pair_close(t_pipe_pair *pp);
void			pipe_pair_init_in(t_pipe_pair *pp, int fd);
void			pipe_pair_init_out(t_pipe_pair *pp, int fd);

#endif
