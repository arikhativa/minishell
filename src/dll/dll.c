/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:47:10 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:35:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll	*dll_create_elem(void *value)
{
	t_dll	*elem;

	elem = ft_calloc(1, sizeof(t_dll));
	if (!elem)
		return (NULL);
	elem->value = value;
	return (elem);
}

void	dll_destroy_elem(t_dll *elem)
{
	ft_bzero(elem, sizeof(t_dll));
	free(elem);
}

void	dll_clear_list(register t_dll *lst, t_dll_destroy_func f)
{
	t_dll	*next;

	while (lst)
	{
		next = lst->next;
		if (f)
			f(&(lst->value));
		dll_destroy_elem(lst);
		lst = next;
	}
}
