/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                          |*---------------------*|   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:28:17 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 02:55:21 by alopez-g     +-----------------------+   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*aux;

	l = *lst;
	while (l != 0)
	{
		aux = l->next;
		if (del)
			(del)(l->content);
		free(l);
		l = aux;
	}
	*lst = 0;
}
