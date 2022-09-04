/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:24 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 02:32:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char	*ft_strtolower(char *str)
{
	char	*t;

	t = str;
	if (!*str)
		return (0);
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (t);
}
