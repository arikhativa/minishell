/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:40 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/08 15:01:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_util.h"

static t_bool	valid_chars(char c)
{
	return (ft_isdigit(c) || PLUS_CHAR == c || MINUS_CHAR == c);
}

static t_bool	valid_sign(char *s, int i)
{
	if (ft_isdigit(s[i + 1]))
		return (TRUE);
	return (FALSE);
}

t_bool	util_is_valid_int(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!valid_chars(s[i]))
			return (FALSE);
		if (PLUS_CHAR == s[i] || MINUS_CHAR == s[i])
			if (!valid_sign(s, i))
				return (FALSE);
		++i;
	}
	return (TRUE);
}
