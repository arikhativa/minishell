/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:10 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/25 14:50:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int	is_special(char *str)
{
	int	i;

	i = 0;
	if (RL_CHAR == *str)
	{
		while (RL_CHAR == *(str + i))
			i++;
		return (i);
	}
	if (RR_CHAR == *str)
	{
		while (RR_CHAR == *(str + i))
			i++;
		return (i);
	}
	if (PIPE_CHAR == *str)
		return (1);
	if (SEMICOLON_CHAR == *str)
		return (1);
	return (0);
}

t_bool	is_dquote(char c)
{
	return (DOUBLE_QUOTE_CHAR == c);
}

t_bool	is_squote(char c)
{
	return (SINGLE_QUOTE_CHAR == c);
}

t_bool	is_space(char c)
{
	return (SPACE_CHAR == c);
}
