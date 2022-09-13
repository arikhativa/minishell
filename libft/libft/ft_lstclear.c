/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:03:57 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 11:08:45 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*node;

	if (!lst | !del)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node->next;
		ft_lstdelone(node, del);
		node = tmp;
	}
	*lst = NULL;
}
