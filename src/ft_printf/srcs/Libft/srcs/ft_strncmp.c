/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:43:28 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:16:08 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (a < (n - 1) && *(s1 + a) && *(s2 + a))
	{
		if (*(s1 + a) != *(s2 + a))
			return (*(unsigned char *)(s1 + a) - *(unsigned char *)(s2 + a));
		a++;
	}
	return (*(unsigned char *)(s1 + a) - *(unsigned char *)(s2 + a));
}
