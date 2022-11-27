/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_exec_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:25 by yoav              #+#    #+#             */
/*   Updated: 2022/11/20 12:09:05 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

static t_error_code	look_in_path_tab(char **ret, char **path_tab, char *exec)
{
	int		i;
	char	*tmp_path;

	*ret = NULL;
	i = ((int)tab_count(path_tab)) - 1;
	while (-1 < i)
	{
		tmp_path = ft_strjoin(path_tab[i], exec);
		if (filer_is_executable(tmp_path))
		{
			*ret = tmp_path;
			return (SUCCESS);
		}
		free(tmp_path);
		--i;
	}
	return (ERROR);
}

static t_bool	is_slash(char *path)
{
	return (NULL != ft_strchr(path, SLASH_CHAR));
}

static t_error_code	slash_logic(t_cmd *c, char *path)
{
	if (filer_is_dir(path))
	{
		c->stt = CMD_IS_DIR;
		return (SUCCESS);
	}
	else if (!filer_is_file(path))
	{
		c->stt = CMD_NOT_FOUND;
		return (SUCCESS);
	}
	else if (!filer_is_exec_prem(path))
	{
		c->stt = PREM_DENIED;
		return (SUCCESS);
	}
	c->exec_path = ft_strdup(path);
	if (!(c->exec_path))
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}

t_error_code	set_exec_path(t_cmd *c, char **path_tab)
{
	t_error_code	err;
	char			*exec;

	exec = cmd_get_cmd(c);
	if (is_slash(exec))
		return (slash_logic(c, exec));
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
	print_error_if_needed(c);
	return (err);
}
