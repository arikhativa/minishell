/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:44:18 by yoav              #+#    #+#             */
/*   Updated: 2022/11/29 13:08:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_error_code	cmd_list_iter(t_cmd_list *l, t_dll_iter f, void *param)
{
	if (!l->lst)
		return (SUCCESS);
	return (dll_iterate(l->lst, f, param));
}

int	cmd_list_size(t_cmd_list *l)
{
	if (!l || !l->lst)
		return (ERROR);
	return (dll_get_size(l->lst));
}
