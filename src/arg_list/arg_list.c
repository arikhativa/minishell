/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:49:42 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 15:55:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_list.h"

t_error_code	arg_list_create(t_arg_list **ret)
{
	t_arg_list	*l;

	l = ft_calloc(1, sizeof(t_arg_list));
	if (!l)
		return (ALLOCATION_ERROR);
	*ret = l;
	return (SUCCESS);
}

void	arg_list_destroy(t_arg_list **l)
{
	t_arg_list	*lst;

	lst = *l;
	dll_clear_list(lst->lst, NULL);
	ft_bzero(lst, sizeof(t_arg_list));
	free(lst);
	*l = NULL;
}

t_error_code	arg_list_add_last(t_arg_list *lst, char *arg)
{
	t_dll	*node;

	node = dll_create_elem(arg);
	if (!node)
		return (ALLOCATION_ERROR);
	dll_add_last(&(lst->lst), node);
	++lst->size;
	return (SUCCESS);
}
