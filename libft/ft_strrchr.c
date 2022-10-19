/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:37:56 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:56:31 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	if (!s)
		return (0);
	ret = (char *)s;
	c = (int)((char)c);
	i = (int)ft_strlen(s);
	if (!c)
		return (ret + i);
	--i;
	while (i >= 0 && ret[i] != c)
		--i;
	if (i == -1)
		return ((char *)0);
	return (ret + i);
}
