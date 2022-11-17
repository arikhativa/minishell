/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:44 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:11:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_LIST_H
# define PIPE_LIST_H

# include <unistd.h>

# include "error_code.h"
# include "dll.h"

typedef struct s_pipe_list
{
	t_dll	*lst;
}	t_pipe_list;

t_error_code	pipe_list_create(t_pipe_list **ret);
void			pipe_list_destroy(t_pipe_list **obj);
void			pipe_list_clean(t_pipe_list *l);
t_error_code	pipe_list_close(t_pipe_list *l);
t_error_code	pipe_list_add(t_pipe_list *l, int pipe[2]);

#endif
