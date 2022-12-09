/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/04 15:24:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_error_code	get_key_value(char *str, char **key, char **value)
{
	size_t	i;

	i = -1;
	while (*(str + ++i))
	{
		if (EQUAL_CHAR == *(str + i))
		{
			*key = ft_substr(str, 0, i);
			*value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
			break ;
		}
	}
	if (!env_is_key_valid(*key))
		return (ERROR);
	return (SUCCESS);
}

t_error_code	builtin_export(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;
	char			*key;
	char			*value;

	c->builtin_ret_val = ERROR;
	if (2 != tab_count(c->argv))
		return (SUCCESS);
	err = get_key_value(*(c->argv + 1), &key, &value);
	if (SUCCESS != err)
	{
		free(key);
		free(value);
		return (SUCCESS);
	}
	c->builtin_ret_val = SUCCESS;
	env_setvar(&sp->envp, key, value);
	return (SUCCESS);
}
