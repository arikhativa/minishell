/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:47:09 by yoav              #+#    #+#             */
/*   Updated: 2022/11/21 18:00:26 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirecter.h"

static int	iter_redirect(t_dll *n, void *param)
{
	t_error_code	err;
	t_redirect		*r;

	(void)param;
	r = n->value;
	err = SUCCESS;
	if (IN == r->type || HEREDOC == r->type)
		err = dup_wrapper(r->fd, STDIN_FILENO);
	if (SUCCESS != err)
		return (err);
	if (OUT == r->type || APPEND == r->type)
		err = dup_wrapper(r->fd, STDOUT_FILENO);
	return (err);
}

t_error_code	redirecter_child_dup_if_needed(t_cmd *c)
{
	if (c->redirect)
		return (dll_iterate(c->redirect->lst, iter_redirect, NULL));
	return (SUCCESS);
}
