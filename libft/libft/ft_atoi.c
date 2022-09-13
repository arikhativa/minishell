/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:21:37 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:44:53 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

static char	*skip_space(char *s)
{
	while (is_space(*s))
		++s;
	return (s);
}

static char	*skip_get_sign(char *s, int *sign)
{
	*sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		++s;
	}
	return (s);
}

int	ft_atoi(const char *nptr)
{
	char	*s;
	int		ret;
	int		sign;

	if (!nptr)
		return (0);
	s = (char *)nptr;
	ret = 0;
	s = skip_space(s);
	s = skip_get_sign(s, &sign);
	while (ft_isdigit(*s))
	{
		ret = (ret * 10) + (*s - '0');
		++s;
	}
	return (ret * sign);
}
