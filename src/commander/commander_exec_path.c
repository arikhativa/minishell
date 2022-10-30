/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_exec_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:25 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 12:32:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

static t_bool	is_file_exist(char *path)
{
	return (SUCCESS == access(path, F_OK));
}

static t_bool	is_exec_prem(char *path)
{
	return (SUCCESS == access(path, X_OK));
}

static t_error_code	look_in_path_tab(char **ret, char **path_tab, char *exec)
{
	int		i;
	char	*tmp_path;

	*ret = NULL;
	i = ((int)tab_count(path_tab)) - 1;
	while (-1 < i)
	{
		tmp_path = ft_strjoin(path_tab[i], exec);
		if (SUCCESS == access(tmp_path, F_OK))
		{
			*ret = tmp_path;
			return (SUCCESS);
		}
		free(tmp_path);
		--i;
	}
	return (ERROR);
}

t_error_code	set_exec_path(t_cmd *c, char **path_tab)
{
	t_error_code	err;
	char			*exec;

	exec = cmd_get_cmd(c);
	if (!exec)
	{
		c->stt = CMD_EMPTY;
		return (SUCCESS);
	}
	if (is_file_exist(exec))
	{
		c->exec_path = ft_strdup(exec);
		if (!(c->exec_path))
			return (ALLOCATION_ERROR);
		return (SUCCESS);
	}
	else
	{
		err = look_in_path_tab(&(c->exec_path), path_tab, exec);
		if (ERROR == err)
			c->stt = CMD_NOT_FOUND;
	}
	return (SUCCESS);
}

int	commander_init_exec_path(t_dll *elem, void *ptr_path_var_tab)
{
	t_error_code	err;
	t_cmd			*c;

	c = (t_cmd *)elem->value;
	c->stt = OK;
	if (is_builtin(cmd_get_cmd(c)))
		return (SUCCESS);
	err = set_exec_path(c, (char **)ptr_path_var_tab);
	if (SUCCESS != err)
		return (err);
	if (OK == c->stt && !is_exec_prem(c->exec_path))
		c->stt = PREM_DENIED;
	print_error_if_needed(c);
	return (SUCCESS);
}
