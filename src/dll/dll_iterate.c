/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_iterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:53:07 by yoav              #+#    #+#             */
/*   Updated: 2022/11/29 13:07:30 by yrabby           ###   ########.fr       */
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

static int	count(t_dll *elem, void *ret)
{
	int	*size;

	(void)elem;
	size = ret;
	++(*size);
	return (SUCCESS);
}

int	dll_get_size(t_dll *l)
{
	int	size;

	size = 0;
	if (!l || ERROR == dll_iterate(l, count, &size))
		return (ERROR);
	return (size);
}
