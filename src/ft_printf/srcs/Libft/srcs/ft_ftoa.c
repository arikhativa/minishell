/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:32:31 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 04:27:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dec_part(long double num, int prc)
{
	char			*str_num;
	char			*aux;
	char			*dec;

	aux = ft_strdup(".");
	while (prc--)
	{
		num = num * (long double)10.0;
		if (!((int)num))
		{
			str_num = aux;
			aux = ft_strjoin(aux, "0");
			free(str_num);
		}
	}
	str_num = ft_uitoa((int)num);
	dec = ft_strjoin(aux, str_num);
	free(aux);
	free(str_num);
	return (dec);
}

char	*ft_ftoa(long double num, int prc)
{
	char			*str_num;
	char			*aux;
	char			*f_aux;

	if (num < 0 && num > -1)
		aux = ft_strdup("-0");
	else
		aux = ft_itoa((int)num);
	num = (num - (int)num) * ((num < 0) * -1 + !(num < 0) * 1);
	f_aux = dec_part(num, prc);
	str_num = ft_strjoin(aux, f_aux);
	free(aux);
	free(f_aux);
	return (str_num);
}
