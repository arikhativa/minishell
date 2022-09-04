/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:16:01 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:15:19 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	aux;

	if (n == 0 || src == dst)
		return (dst);
	aux = 0;
	while (aux < n)
	{
		*(unsigned char *)(dst + aux) = *(unsigned char *)(src + aux);
		aux++;
	}
	return ((void *)dst);
}
