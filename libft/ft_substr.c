/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:34:07 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:57:17 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	substr_len;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start > str_len)
		return (ft_strdup(""));
	substr_len = str_len - start;
	if (substr_len < len)
		len = substr_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
		ft_strlcpy(ret, (s + start), len + 1);
	return (ret);
}
