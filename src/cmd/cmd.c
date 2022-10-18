/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:45:35 by yoav              #+#    #+#             */
/*   Updated: 2022/10/18 14:27:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_error_code	cmd_create(t_cmd **ret)
{
	t_cmd	*c;

	c = ft_calloc(1, sizeof(t_cmd));
	if (!c)
		return (ALLOCATION_ERROR);
	*ret = c;
	return (SUCCESS);
}

void	cmd_destroy(t_cmd **cmd)
{
	t_cmd	*c;

	c = *cmd;
	tab_shallow_destroy(&(c->argv));
	ft_bzero(c, sizeof(t_cmd));
	free(c);
	*cmd = NULL;
}

t_error_code	cmd_add_arg(t_cmd *c, char *arg)
{
	t_error_code	err;

	if (!c->argv)
	{
		err = tab_create(&(c->argv), 2);
		if (SUCCESS != err)
			return (ALLOCATION_ERROR);
		c->argv[0] = arg;
		c->argv[1] = NULL;
		return (SUCCESS);
	}
	err = tab_add(&(c->argv), arg);
	if (SUCCESS != err)
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}

char	*cmd_get_cmd(t_cmd *c)
{
	return (c->argv[0]);
}
