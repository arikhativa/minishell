/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:10:14 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/26 16:06:29 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_aux;

	if (!lst)
		return (0);
	del = (void *)del;
	new_list = ft_lstnew(f(lst->content));
	new_list_aux = new_list;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		lst = lst->next;
		new_list = new_list->next;
	}
	return (new_list_aux);
}
