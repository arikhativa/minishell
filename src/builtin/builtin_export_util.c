/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/08 17:04:27 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_key_and_value(char *s, int fd)
{
	while (*s && *s != EQUAL_CHAR)
	{
		ft_putchar_fd(*s, fd);
		++s;
	}
	ft_putchar_fd(*s, fd);
	++s;
	ft_putstr_fd(DOUBLE_QUOTE_STR, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DOUBLE_QUOTE_STR, fd);
}

t_bool	export_is_input_valid(char *s)
{
	if (!ft_isalpha(*s) && UNDERSCORE_CHAR != *s)
		return (FALSE);
	++s;
	while (*s && *s != EQUAL_CHAR)
	{
		if (!ft_isalnum(*s) && UNDERSCORE_CHAR != *s)
			return (FALSE);
		++s;
	}
	return (TRUE);
}

t_bool	export_should_ignore_input(char *s)
{
	while (*s && *s != EQUAL_CHAR)
		++s;
	if (!*s)
		return (TRUE);
	return (FALSE);
}

t_error_code	export_print_all(char **tab, int fd)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(EXPORT_PREFIX, fd);
		print_key_and_value(tab[i], fd);
		ft_putstr_fd("\n", fd);
		++i;
	}
	ft_putstr_fd("\n", fd);
	return (SUCCESS);
}
