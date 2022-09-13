/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:06:08 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:39:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_list.h"

t_error_code	token_list_create(t_token_list **ret)
{
	*ret = ft_calloc(1, sizeof(t_token_list));
	if (!*ret)
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}

void	token_list_destroy(t_token_list	**lst)
{
	dll_clear_list((*lst)->tok_lst, (t_dll_destroy_func)token_destroy);
	free(*lst);
	*lst = NULL;
}

t_error_code	token_list_add_last(t_token_list *lst, t_token *t)
{
	t_dll			*node;

	node = dll_create_elem(t);
	if (!node)
		return (ALLOCATION_ERROR);
	dll_add_last(&(lst->tok_lst), node);
	return (SUCCESS);
}
