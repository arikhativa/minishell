/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:09:22 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:14:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	aux;

	aux = 0;
	while (aux < n)
		*(unsigned char *)(s + aux++) = 0;
}
