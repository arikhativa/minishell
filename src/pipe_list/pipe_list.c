/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:38 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:20:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_list.h"

t_error_code	pipe_list_create(t_pipe_list **ret)
{
	t_pipe_list	*l;

	l = ft_calloc(1, sizeof(t_pipe_list));
	if (!l)
		return (ALLOCATION_ERROR);
	*ret = l;
	return (SUCCESS);
}

static void	pipe_destroy(int **p)
{
	ft_bzero(*p, sizeof(int) * 2);
	free(*p);
	*p = NULL;
}

void	pipe_list_destroy(t_pipe_list **obj)
{
	t_pipe_list	*l;

	l = *obj;
	dll_clear_list(l->lst, (t_dll_destroy_func)pipe_destroy);
	ft_bzero(l, sizeof(t_pipe_list));
	free(l);
	*obj = NULL;
}

void	pipe_list_clean(t_pipe_list *l)
{
	dll_clear_list(l->lst, (t_dll_destroy_func)pipe_destroy);
	l->lst = NULL;
}

t_error_code	pipe_list_add(t_pipe_list *l, int pipe[2])
{
	t_dll	*n;
	int		*p;

	p = ft_calloc(1, sizeof(int) * 2);
	if (!p)
		return (ALLOCATION_ERROR);
	p[PIPE_READ] = pipe[PIPE_READ];
	p[PIPE_WRITE] = pipe[PIPE_WRITE];
	n = dll_create_elem(p);
	if (!n)
	{
		free(p);
		return (ALLOCATION_ERROR);
	}
	dll_add_last(&(l->lst), n);
	return (SUCCESS);
}
