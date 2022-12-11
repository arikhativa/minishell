/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:48:14 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/11 11:03:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static t_bool	is_valid_char(char c)
{
	if (!c || SPACE_CHAR == c)
		return (FALSE);
	if (ft_isalnum(c) || UNDERSCORE_CHAR == c)
		return (TRUE);
	return (FALSE);
}

t_bool	env_is_key_valid(char *key)
{
	int	i;

	i = 0;
	while (*(key + i))
	{
		if (!is_valid_char(*(key + i)))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_error_code	env_inc_shlvl(char ***env)
{
	t_error_code	err;
	int				lvl_int;
	char			*lvl_str;

	lvl_str = env_getvar(*env, SHLVL_KEY);
	lvl_int = ft_atoi(lvl_str);
	if (0 > lvl_int || !lvl_str)
		lvl_int = 0;
	else
		++lvl_int;
	lvl_str = ft_itoa(lvl_int);
	if (!lvl_str)
		return (ALLOCATION_ERROR);
	err = env_setvar(env, SHLVL_KEY, lvl_str);
	free(lvl_str);
	return (err);
}

void	env_set_pwd(char ***env)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	env_setvar(env, PWD_VAR, tmp);
	free(tmp);
}
