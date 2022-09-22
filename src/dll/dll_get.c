/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:54:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/09/22 17:01:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll	*dll_get_n_node(t_dll *node, int i)
{
	while (i)
	{
		node = node->next;
		--i;
	}
	return (node);
}

t_dll	*dll_get_last_elem(t_dll *lst)
{
	register t_dll	*next;

	if (!lst)
		return (NULL);
	next = lst->next;
	while (next)
	{
		lst = next;
		next = lst->next;
	}
	return (lst);
}
