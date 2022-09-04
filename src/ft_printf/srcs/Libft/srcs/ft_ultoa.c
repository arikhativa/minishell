/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:22:50 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 20:38:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long	udigit(unsigned long n)
{
	unsigned long	aux;

	aux = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n = n / 10;
		aux++;
	}
	return (aux);
}

char	*ft_ultoa(unsigned long n)
{
	char			*str;
	unsigned long	len;
	unsigned long	aux;
	unsigned long	nb;

	nb = (unsigned long)n;
	aux = 0;
	len = udigit(nb);
	if (nb < 0)
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	*(str + len--) = 0;
	if (nb < 0)
		nb *= -1;
	while (aux <= len)
	{
		*(str + len - aux) = nb % 10 + 48;
		nb = nb / 10;
		aux++;
	}
	if (ft_strlen(str) > 1 && *str == 48)
		*str = 45;
	return (str);
}
