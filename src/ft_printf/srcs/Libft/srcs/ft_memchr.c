/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:06:43 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:15:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	aux;

	aux = 0;
	while (aux < n)
	{
		if (*(unsigned char *)(s + aux) == (unsigned char)c)
			return ((void *)(s + aux));
		aux++;
	}
	return (0);
}
