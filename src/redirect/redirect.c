/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:46:29 by yoav              #+#    #+#             */
/*   Updated: 2022/11/21 18:06:46 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

t_error_code	redirect_create(t_redirect **ret)
{
	*ret = ft_calloc(1, sizeof(t_redirect));
	if (!(*ret))
		return (ALLOCATION_ERROR);
	(*ret)->fd = ERROR;
	return (SUCCESS);
}

void	redirect_init(t_redirect *r, char *path, t_redirect_type t)
{
	r->type = t;
	r->path = path;
}

void	redirect_destroy(t_redirect **r)
{
	if (HEREDOC == (*r)->type)
	{
		unlink((*r)->path);
		free((*r)->path);
	}
	if (ERROR != (*r)->fd)
		close((*r)->fd);
	ft_bzero(*r, sizeof(t_redirect));
	free(*r);
	*r = NULL;
}
