/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:39:07 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:43:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_dll	*cmd_list_get_list(t_cmd_list *lst)
{
	return (lst->lst);
}

t_dll	*cmd_list_get_next_cmd(t_dll *node)
{
	return (node->next);
}
