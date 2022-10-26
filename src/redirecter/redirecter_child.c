/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:47:09 by yoav              #+#    #+#             */
/*   Updated: 2022/10/27 11:47:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirecter.h"

static int	iter_redirect(t_dll *n, void *param)
{
	t_redirect	*r;

	(void)param;
	r = n->value;
	if (IN == r->type)
		dup2(r->fd, STDIN_FILENO);
	if (OUT == r->type || APPEND == r->type)
		dup2(r->fd, STDOUT_FILENO);
	return (SUCCESS);
}

void	redirecter_child_dup_if_needed(t_cmd *c)
{
	if (c->redirect)
		dll_iterate(c->redirect->lst, iter_redirect, NULL);
}
