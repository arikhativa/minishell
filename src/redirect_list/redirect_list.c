/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:26:32 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 19:42:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_list.h"

t_error_code	redirect_list_create(t_redirect_list **ret)
{
	t_redirect_list	*l;

	l = ft_calloc(1, sizeof(t_redirect_list));
	if (!l)
		return (ALLOCATION_ERROR);
	*ret = l;
	return (SUCCESS);
}

void	redirect_list_destroy(t_redirect_list **list)
{
	t_redirect_list	*l;

	l = *list;
	dll_clear_list(l->lst, (t_dll_destroy_func)redirect_destroy);
	ft_bzero(l, sizeof(t_redirect_list));
	free(l);
	*list = NULL;
}

t_error_code	redirect_list_add(t_redirect_list *l, char *path, \
	t_redirect_type t)
{
	t_dll			*node;
	t_redirect		*r;
	t_error_code	err;

	err = redirect_create(&r);
	if (SUCCESS != err)
		return (err);
	redirect_init(r, path, t);
	node = dll_create_elem(r);
	if (!node)
	{
		redirect_destroy(&r);
		return (ALLOCATION_ERROR);
	}
	dll_add_last(&(l->lst), node);
	return (SUCCESS);
}

t_redirect	*redirect_list_get_last(t_redirect_list *l)
{
	t_dll	*n;

	if (l->lst)
	{
		n = dll_get_last_elem(l->lst);
		return (n->value);
	}
	return (NULL);
}
