/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:47:09 by yoav              #+#    #+#             */
/*   Updated: 2022/11/22 10:47:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirecter.h"

static void	set_stream(t_cmd *c, t_redirect *r)
{
	t_redirect_type	t;

	t = r->type;
	if (IN == t)
		c->in_stream = r->fd;
	else if (OUT == t || APPEND == t)
		c->out_stream = r->fd;
}

t_error_code	redirecter_set_stream_if_needed(t_cmd *c)
{
	t_dll	*n;

	if (c->redirect)
	{
		n = dll_get_last_elem(c->redirect->lst);
		if (n)
			set_stream(c, n->value);
	}
	return (SUCCESS);
}
