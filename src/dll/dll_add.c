/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:03:46 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:11:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	dll_add_after(t_dll *lst, t_dll *new_elem)
{
	t_dll	*next;

	next = lst->next;
	lst->next = new_elem;
	new_elem->next = next;
	new_elem->prev = lst;
	if (next)
		next->prev = new_elem;
}

void	dll_add_before(t_dll *lst, t_dll *new_elem)
{
	t_dll	*next;

	dll_add_after(lst, new_elem);
	next = lst->next;
	dll_swap_value(lst, next);
}

void	dll_add_last(t_dll **lst, t_dll *new_elem)
{
	t_dll			*elem;
	register t_dll	*next;

	if (!(*lst))
	{
		*lst = new_elem;
		return ;
	}
	elem = *lst;
	next = elem->next;
	while (next)
	{
		elem = next;
		next = elem->next;
	}
	dll_add_after(elem, new_elem);
}
