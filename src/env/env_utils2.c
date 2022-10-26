/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:48:14 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/23 15:38:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_bool	is_key_valid(char *key)
{
	int	i;

	i = 0;
	while (*(key + ++i))
	{
		if (' ' == *(key + i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_error_code	env_inc_shlvl(char ***env)
{
	int		lvl_int;
	char	*lvl_str;

	lvl_str = env_getvar(*env, SHLVL_KEY);
	lvl_int = ft_atoi(lvl_str);
	if (0 > lvl_int || !lvl_str)
		lvl_int = 0;
	else
		++lvl_int;
	lvl_str = ft_itoa(lvl_int);
	if (!lvl_str)
		return (ALLOCATION_ERROR);
	return (env_setvar(env, SHLVL_KEY, lvl_str));
}
