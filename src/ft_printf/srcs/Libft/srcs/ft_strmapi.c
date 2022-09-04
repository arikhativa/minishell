/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:14:57 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:22:07 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	aux;
	char	*str;

	aux = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !str)
		return (0);
	while (*(s + aux))
	{
		*(str + aux) = f(aux, *(s + aux));
		aux++;
	}
	*(str + aux) = 0;
	return (str);
}
