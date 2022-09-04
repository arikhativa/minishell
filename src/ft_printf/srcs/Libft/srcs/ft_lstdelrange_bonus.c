/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelrange_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:58:32 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/27 21:42:33 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelrange(t_list **from, t_list **to, int ton, void (*del)(void *))
{
	t_list	*t;

	if (to)
	{
		while (from != to)
		{
			t = (*from)->next;
			ft_lstdelone(from, del);
			*from = t;
		}
	}
	else if (ton)
	{
		while (ton--)
		{
			t = (*from)->next;
			ft_lstdelone(from, del);
			*from = t;
		}
	}
}
