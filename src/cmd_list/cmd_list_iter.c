/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:44:18 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 10:23:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_error_code	cmd_list_iter(t_cmd_list *l, t_dll_iter f, void *param)
{
	if (!l->lst)
		return (SUCCESS);
	return (dll_iterate(l->lst, f, param));
}
