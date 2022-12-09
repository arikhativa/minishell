/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:10 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/04 15:21:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

t_bool	reader_is_special(char *str)
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
	return (0);
}

t_bool	reader_is_dquote(char c)
{
	return (DOUBLE_QUOTE_CHAR == c);
}

t_bool	reader_is_squote(char c)
{
	return (SINGLE_QUOTE_CHAR == c);
}

t_bool	reader_is_space(char c)
{
	return (SPACE_CHAR == c);
}

char	*reader_get_quote_prompt(char c)
{
	if (reader_is_dquote(c))
		return (DQUOTE_PROMPT);
	if (reader_is_squote(c))
		return (SQUOTE_PROMPT);
	return (NULL);
}
