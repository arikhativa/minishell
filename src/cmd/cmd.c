/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:45:35 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 10:20:47 by yoav             ###   ########.fr       */
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
	err = redirect_list_create(&(c->redirect));
	if (SUCCESS != err)
	{
		free(c);
		return (ALLOCATION_ERROR);
	}
	err = pipe_pair_create(&(c->pp));
	if (SUCCESS != err)
	{
		redirect_list_destroy(&(c->redirect));
		free(c);
		return (ALLOCATION_ERROR);
	}
	*ret = c;
	return (SUCCESS);
}

void	cmd_destroy(t_cmd **cmd)
{
	t_cmd	*c;

	c = *cmd;
	if (c->argv)
		tab_shallow_destroy(&(c->argv));
	if (c->exec_path)
	{
		ft_bzero(c->exec_path, ft_strlen(c->exec_path));
		free(c->exec_path);
	}
	if (c->redirect)
		redirect_list_destroy(&(c->redirect));
	if (c->pp)
		pipe_pair_destroy(&(c->pp));
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
	if (!c->argv)
		return (NULL);
	return (c->argv[0]);
}
