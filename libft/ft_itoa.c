/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:31:37 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 14:04:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	count_digit(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= BASE_DEC;
		++i;
	}
	return (i);
}

static void	rec(long n, char *buff)
{
	if (n / BASE_DEC)
	{
		rec(n / BASE_DEC, buff - 1);
		rec(n % BASE_DEC, buff);
	}
	if (n < BASE_DEC)
		*buff = n + '0';
}

static void	get_sign(long *nbr, int *sign, int *digit)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		*sign = -1;
		++(*digit);
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nbr;
	int		sign;
	int		digit;

	nbr = (long)n;
	sign = 1;
	digit = count_digit(nbr);
	get_sign(&nbr, &sign, &digit);
	ret = (char *)malloc(sizeof(char) * (digit + 1));
	if (ret)
	{
		ret[digit] = 0;
		if (sign == -1)
			ret[0] = '-';
		rec(nbr, (ret + digit - 1));
	}
	return (ret);
}
