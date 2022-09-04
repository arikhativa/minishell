/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:20:02 by alopez-g          #+#    #+#             */
/*   Updated: 2020/07/07 17:15:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	aux;

	aux = 0;
	while (*(s + aux))
	{
		if ((unsigned char)*(s + aux) == (unsigned char)c)
			return ((char *)(s + aux));
		aux++;
	}
	if (*(unsigned char *)(s + aux) == (unsigned char)c)
		return ((char *)(s + aux));
	return (0);
}
