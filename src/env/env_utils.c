/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:14:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 01:45:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_key_value_pair(char *key, char *value)
{
	char	*pair;
	char	*tmp;

	tmp = ft_strjoin(key, EQUAL_STR);
	pair = ft_strjoin(tmp, value);
	free(tmp);
	return (pair);
}

t_error_code	new_var(char ***env, char *key, char *value)
{
	if (!*env)
	{
		*env = (char **)malloc(sizeof(char *));
		**env = NULL;
	}
	return (tab_add(&(*env), get_key_value_pair(key, value)));
}

char	*get_value(char *env_var)
{
	char	*pos;

	pos = ft_strchr((const char *)env_var, EQUAL_CHAR);
	return (pos + 1);
}

t_bool	is_key(char *env, char *key)
{
	char	*pos;
	char	i;

	pos = ft_strchr((const char *)env, EQUAL_CHAR);
	i = 0;
	while ((env + i) != pos && *(key + i))
	{
		if (*(env + i) != *(key + i))
			return (FALSE);
		i++;
	}
	if (*(key + i) == '\0' && *(env + i) == EQUAL_CHAR)
		return (TRUE);
	return (FALSE);
}

void	fill_mem(char **to_empty, char **new_element)
{
	free(*to_empty);
	*to_empty = *new_element;
	*new_element = NULL;
}
