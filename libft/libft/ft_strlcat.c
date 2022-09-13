/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:30:05 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:56:06 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dest_len > size)
		return (src_len + size);
	if (size == 0)
		return (src_len);
	while (src[i] && (i + dest_len + 1) < size)
	{
		dst[dest_len + i] = src[i];
		++i;
	}
	dst[dest_len + i] = 0;
	return (src_len + dest_len);
}
