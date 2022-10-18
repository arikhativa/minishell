/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_path_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:45:24 by yoav              #+#    #+#             */
/*   Updated: 2022/10/20 14:02:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

static t_error_code	add_slash_if_needed_line(char **ret)
{
	char	*last_slash;
	char	*tmp;
	char	*path;

	path = *ret;
	last_slash = ft_strrchr(path, SLASH_CHAR);
	if (last_slash[1])
	{
		tmp = path;
		path = ft_strjoin(tmp, SLASH_STR);
		free(tmp);
		if (!path)
			return (ALLOCATION_ERROR);
	}
	*ret = path;
	return (SUCCESS);
}

static t_error_code	add_slash_if_needed(char **tab)
{
	t_error_code	err;
	int				i;

	i = 0;
	while (tab[i])
	{
		err = add_slash_if_needed_line(tab + i);
		if (SUCCESS != err)
			return (err);
		++i;
	}
	return (SUCCESS);
}

t_error_code	get_path_tab(char ***ret, char **env)
{
	t_error_code	err;
	char			*path;
	char			**path_tab;

	path = env_getvar(env, PATH_KEY);
	path_tab = ft_split(path, COLON_CHAR);
	err = add_slash_if_needed(path_tab);
	if (SUCCESS != err)
		tab_deep_destroy(&path_tab);
	*ret = path_tab;
	return (err);
}
