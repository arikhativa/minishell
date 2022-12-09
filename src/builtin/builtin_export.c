/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/09 10:23:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_error_code	get_key_value(char *str, char **key, char **value)
{
	size_t	i;

	if (!export_is_input_valid(str))
		return (EXPORT_INVALID_INPUT);
	if (export_should_ignore_input(str))
		return (EXPORT_IGNORE_INPUT);
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

static t_error_code	export_one(t_shell_op *sp, t_cmd *c, char *line)
{
	t_error_code	err;
	char			*key;
	char			*value;

	c->builtin_ret_val = SUCCESS;
	err = get_key_value(line, &key, &value);
	if (EXPORT_IGNORE_INPUT == err)
		return (SUCCESS);
	if (EXPORT_INVALID_INPUT == err)
	{
		error_code_print(3, EXPORT_ERR_STR, line, EXPORT_INVALID_ARG);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (SUCCESS);
	}
	if (SUCCESS != err)
	{
		free(key);
		free(value);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (err);
	}
	err = env_setvar(&sp->envp, key, value);
	return (err);
}

t_error_code	builtin_export(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;
	size_t			i;

	err = SUCCESS;
	c->builtin_ret_val = SUCCESS;
	if (1 == tab_count(c->argv))
		return (export_print_all(sp->envp, c->out_stream));
	i = 1;
	while (err == SUCCESS && c->argv[i])
	{
		err = export_one(sp, c, c->argv[i]);
		++i;
	}
	return (SUCCESS);
}
