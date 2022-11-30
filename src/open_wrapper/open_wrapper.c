/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:15:11 by yoav              #+#    #+#             */
/*   Updated: 2022/11/21 17:46:43 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "open_wrapper.h"

t_error_code	open_wrapper(int *ret, char *path, int flags)
{
	int	fd;

	fd = open(path, flags, FILE_PERM);
	if (ERROR == fd)
		return (OPEN_ERROR);
	*ret = fd;
	return (SUCCESS);
}

int	get_flags(t_redirect_type t)
{
	if (IN == t || HEREDOC == t)
		return (O_RDONLY);
	if (OUT == t)
		return (O_CREAT | O_WRONLY | O_TRUNC);
	if (APPEND == t)
		return (O_CREAT | O_WRONLY | O_APPEND);
	return (NON);
}

t_error_code	open_file(t_redirect *r)
{
	return (open_wrapper(&(r->fd), r->path, get_flags(r->type)));
}
