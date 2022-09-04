/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:19:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:22:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	start_index(char const *s1, char const *set)
{
	int	aux;

	aux = 0;
	while (ft_strchr(set, *(s1 + aux)) && *(s1 + aux))
		aux++;
	return (aux);
}

static int	final_index(char const *s1, char const *set)
{
	const char	*aux;
	int			len;

	aux = s1;
	len = (int)ft_strlen(s1) - 1;
	while (ft_strchr(set, *(s1 + len)) && (s1 + len) != aux)
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;

	if (!s1 || !set)
		return (0);
	start = start_index(s1, set);
	len = final_index(s1, set) - start + 1;
	if (final_index(s1, set) < start_index(s1, set))
		return (ft_calloc(sizeof(char), 1));
	return (ft_substr(s1, start, len));
}
