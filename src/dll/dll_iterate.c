/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_iterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:53:07 by yoav              #+#    #+#             */
/*   Updated: 2022/09/06 13:32:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_error_code	dll_iterate(register t_dll *lst, t_dll_iter f, void *param)
{
	register int	stt;

	stt = SUCCESS;
	while (lst && SUCCESS == stt)
	{
		stt = f(lst, param);
		lst = lst->next;
	}
	return (stt);
}
