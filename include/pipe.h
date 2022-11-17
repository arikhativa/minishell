/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:10:10 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 11:54:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "error_code.h"
# include "macro.h"

typedef enum e_pipe_type
{
	PIPE_ERROR = 0,
	PIPE_IN = 1,
	PIPE_OUT = 2,
}	t_pipe_type;

typedef struct s_pipe
{
	t_bool		on;
	t_pipe_type	type;
	int			fd;
}	t_pipe;

t_error_code	pipe_create(t_pipe **ret);
void			pipe_destroy(t_pipe **obj);
void			pipe_init(t_pipe *p, t_pipe_type t, int fd);
t_error_code	pipe_close(t_pipe *p);

#endif
