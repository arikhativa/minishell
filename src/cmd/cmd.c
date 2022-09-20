/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:45:35 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 16:42:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_error_code	cmd_create(t_cmd **ret)
{
	t_error_code	err;
	t_cmd			*c;

	c = ft_calloc(1, sizeof(t_cmd));
	if (!c)
		return (ALLOCATION_ERROR);
	err = arg_list_create(&(c->args));
	if (SUCCESS != err)
	{
		ft_bzero(c, sizeof(t_cmd));
		free(c);
		return (err);
	}
	*ret = c;
	return (SUCCESS);
}

void	cmd_destroy(t_cmd **cmd)
{
	t_cmd	*c;

	c = *cmd;
	arg_list_destroy(&(c->args));
	ft_bzero(c, sizeof(t_cmd));
	free(c);
	*cmd = NULL;
}

t_error_code	cmd_add_arg(t_cmd *c, char *arg)
{
	t_error_code	err;

	err = arg_list_add_last(c->args, arg);
	if (SUCCESS != err)
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}
