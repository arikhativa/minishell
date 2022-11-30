/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/18 23:38:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "expander.h"
#include "libft.h"
#include "tab.h"

static t_bool	key_is_valid(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	value_is_valid(char *str)
{
	(void)str;
	return (TRUE);
}

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
	if (!key_is_valid(*key) || !value_is_valid(*value))
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
