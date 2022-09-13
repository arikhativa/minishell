/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:47:40 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:55:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret)
	{
		ret[i] = 0;
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			++i;
		}
	}
	return (ret);
}
