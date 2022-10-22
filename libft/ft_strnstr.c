/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:11:02 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 11:42:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	l;
	size_t			i;

	i = 0;
	l = ft_strlen(little);
	if (!l)
		return ((char *)big);
	while (big[i] && (i + l - 1) < len)
	{
		if (!ft_strncmp((big + i), little, l))
			return ((char *)big + i);
		++i;
	}
	return ((char *)0);
}
