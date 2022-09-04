/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:13:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:13:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	aux;

	aux = 0;
	s = malloc(count * size);
	if (!s)
		return (0);
	while (aux < (count * size))
	{
		*(unsigned char *)(s + aux) = 0;
		aux++;
	}
	return (s);
}
