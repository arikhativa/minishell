/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:47:10 by yoav              #+#    #+#             */
/*   Updated: 2022/09/06 14:09:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll	*dll_create_elem(void *value)
{
	t_dll	*elem;

	// TODO create calloc here
	elem = malloc(1);
	if (!elem)
		return (NULL);
	elem->value = value;
	return (elem);
}

void	dll_destroy_elem(t_dll *elem)
{
	// TODO
	// ft_bzero(elem, sizeof(t_dll));
	free(elem);
}

void	dll_clear_list(register t_dll *lst)
{
	t_dll	*next;

	while (lst)
	{
		next = lst->next;
		dll_destroy_elem(lst);
		lst = next;
	}
}
