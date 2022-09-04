/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:03:12 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 13:50:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long double	get_decimal_part(const char *str)
{
	int			cnt;
	long double	f;

	cnt = 0;
	str++;
	f = 0.0;
	while (*(str + cnt) >= 48 && *(str + cnt) <= 57)
		f = f * 10 + (*(str + cnt++) - 48);
	while (cnt--)
		f = f / (long double)10;
	return (f);
}

long double	ft_atof(const char *str)
{
	long double	aux;
	int			sign;

	aux = 0.0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		aux = aux * 10 + (long double)(*str - 48);
		str++;
	}
	if (*str == '.')
		aux += get_decimal_part(str++);
	return (aux * sign);
}
