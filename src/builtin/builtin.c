/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:05 by yoav              #+#    #+#             */
/*   Updated: 2022/11/22 10:43:06 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// For every new builtin add a line like this:
// ret *= ft_strcmp(word, BUILTIN_XXX_STR);
// if any of them is TRUE then ret will be 0 so !0 -> TRUE
// if none are, then !TRUE -> FALSE
t_bool	is_builtin(char *word)
{
	int	ret;

	if (!word)
		return (FALSE);
	ret = TRUE;
	ret *= ft_strcmp(word, BUILTIN_ECHO_STR);
	ret *= ft_strcmp(word, BUILTIN_CD_STR);
	ret *= ft_strcmp(word, BUILTIN_PWD_STR);
	ret *= ft_strcmp(word, BUILTIN_EXPORT_STR);
	ret *= ft_strcmp(word, BUILTIN_UNSET_STR);
	ret *= ft_strcmp(word, BUILTIN_ENV_STR);
	ret *= ft_strcmp(word, BUILTIN_EXIT_STR);
	return (!ret);
}

t_builtin	builtin_get_func(char *word)
{
	if (!word)
		return (NULL);
	if (!ft_strcmp(word, BUILTIN_ECHO_STR))
		return (builtin_echo);
	if (!ft_strcmp(word, BUILTIN_CD_STR))
		return (builtin_cd);
	if (!ft_strcmp(word, BUILTIN_PWD_STR))
		return (builtin_pwd);
	if (!ft_strcmp(word, BUILTIN_EXPORT_STR))
		return (builtin_export);
	if (!ft_strcmp(word, BUILTIN_UNSET_STR))
		return (builtin_unset);
	if (!ft_strcmp(word, BUILTIN_ENV_STR))
		return (builtin_env);
	if (!ft_strcmp(word, BUILTIN_EXIT_STR))
		return (builtin_exit);
	return (NULL);
}
