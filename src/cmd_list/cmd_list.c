/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:44:18 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 16:44:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_error_code	cmd_list_create(t_cmd_list **ret)
{
	t_cmd_list	*c;

	c = ft_calloc(1, sizeof(t_cmd_list));
	if (!c)
		return (ALLOCATION_ERROR);
	*ret = c;
	return (SUCCESS);
}

void	cmd_list_destroy(t_cmd_list **cmd_list)
{
	t_cmd_list	*c;

	c = *cmd_list;
	dll_clear_list(c->lst, (t_dll_destroy_func)cmd_destroy);
	ft_bzero(c, sizeof(t_cmd_list));
	free(c);
	*cmd_list = NULL;
}

t_error_code	cmd_list_add_cmd(t_cmd_list *lst, t_cmd *c)
{
	t_dll	*node;

	node = dll_create_elem(c);
	if (!node)
		return (ALLOCATION_ERROR);
	dll_add_last(&(lst->lst), node);
	return (SUCCESS);
}
