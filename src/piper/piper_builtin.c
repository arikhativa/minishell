/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:34:51 by yoav              #+#    #+#             */
/*   Updated: 2022/11/22 10:48:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piper.h"

t_error_code	piper_set_stream_if_needed(t_cmd *c)
{
	if (!c || !c->pp)
		return (ERROR);
	if (c->pp)
	{
		if (c->pp->in->on)
			c->in_stream = c->pp->in->fd;
		if (c->pp->out->on)
			c->out_stream = c->pp->out->fd;
	}
	return (SUCCESS);
}
