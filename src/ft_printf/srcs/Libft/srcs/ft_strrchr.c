/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:25:27 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:16:14 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	aux;

	aux = ft_strlen(s) - 1;
	if (*(unsigned char *)(s + aux + 1) == (unsigned char)c)
		return ((char *)(s + aux + 1));
	while (aux >= 0)
	{
		if (*(unsigned char *)(s + aux) == (unsigned char)c)
			return ((char *)(s + aux));
		aux--;
	}
	return (0);
}
