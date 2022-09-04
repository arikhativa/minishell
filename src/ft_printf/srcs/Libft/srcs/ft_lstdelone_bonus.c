/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:20:07 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/28 00:22:50 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{
	t_list	*nx;
	t_list	*pv;

	nx = (*lst)->next;
	pv = (*lst)->prev;
	pv->next = nx;
	if (nx)
		nx->prev = pv;
	if (del)
		(del)((*lst)->content);
	free(*lst);
	*lst = nx;
}
