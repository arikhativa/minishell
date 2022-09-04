/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:26:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 13:20:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_strisdigit(char *c)
{
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (0);
		c++;
	}
	return (1);
}

int	ft_strisfdigit(char *c)
{
	char	p_cnt;

	p_cnt = 0;
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	while (*c)
	{
		if (*c == '.')
			p_cnt++;
		if (!ft_isdigit(*c) && *c != '.')
			return (0);
		c++;
	}
	if (p_cnt > 1)
		return (0);
	return (1);
}
