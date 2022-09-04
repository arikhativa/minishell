/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:29:45 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:15:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	aux;
	int		j;

	if (len == 0 || dst == src)
		return (dst);
	if (src < dst)
	{
		j = (int)len - 1;
		while (j >= 0)
		{
			*(unsigned char *)(dst + j) = *(unsigned char *)(src + j);
			j--;
		}
		return (dst);
	}
	aux = 0;
	while (aux < len)
	{
		*(unsigned char *)(dst + aux) = *(unsigned char *)(src + aux);
		aux++;
	}
	return (dst);
}
