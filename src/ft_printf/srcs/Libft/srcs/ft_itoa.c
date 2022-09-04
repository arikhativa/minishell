/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:22:50 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:16:14 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	digit(int n)
{
	int	aux;

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

static int	udigit(unsigned int n)
{
	int	aux;

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

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		aux;
	long	nb;

	nb = (long)n;
	aux = 0;
	len = digit(nb);
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

char	*ft_uitoa(int n)
{
	char			*str;
	int				len;
	int				aux;
	unsigned int	nb;

	nb = (unsigned int)n;
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
