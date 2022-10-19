/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:25:52 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:20:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	sum;

	sum = size * nmemb;
	if (size != 0 && sum / size != nmemb)
		return (NULL);
	ret = malloc(sum);
	if (ret)
		ft_bzero(ret, nmemb * size);
	return (ret);
}
