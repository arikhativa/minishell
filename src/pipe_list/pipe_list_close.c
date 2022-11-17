/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:38 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:20:48 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_list.h"

static int	iter_close(t_dll *n, void *param)
{
	t_error_code	err;
	int				*p;

	(void)param;
	if (!n)
		return (SUCCESS);
	p = n->value;
	err = close(p[PIPE_WRITE]);
	if (SUCCESS != err)
		return (CLOSE_ERROR);
	err = close(p[PIPE_READ]);
	if (SUCCESS != err)
		return (CLOSE_ERROR);
	return (SUCCESS);
}

t_error_code	pipe_list_close(t_pipe_list *l)
{
	if (!l || !l->lst)
		return (SUCCESS);
	return (dll_iterate(l->lst, iter_close, NULL));
}
