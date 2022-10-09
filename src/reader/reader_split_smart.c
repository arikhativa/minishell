/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/25 14:50:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	is_word(char *str)
{
	char	del;
	int		i;

	i = is_special(str);
	if (i)
		return (i);
	else
		i = -1;
	del = SPACE_CHAR;
	while (*(str + ++i) && *(str + i) != del)
	{
		if (is_space(del) && is_special(str + i))
			return (i);
		if ((is_dquote(*(str + i)) && *(str + i) != del && !is_squote(del))
			|| (is_squote(*(str + i)) && *(str + i) != del && !is_dquote(del)))
			del = *(str + i);
		if (!is_space(del) && *(str + i + 1) == del)
		{
			del = SPACE_CHAR;
			i += 1;
		}
	}
	return (i + 1 + (is_dquote(del) || is_squote(del)) - is_space(*(str + i)));
}

int	cnt_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (*(str + i))
	{
		while (is_space(*(str + i)))
			i++;
		i += is_word(str + i);
		words++;
		while (is_space(*(str + i)))
			i++;
	}
	return (words);
}

t_error_code	allocate_words(char *src, char ***ret, int size)
{
	int		words;
	int		i;
	int		len;

	len = 0;
	i = 0;
	words = -1;
	while (++words < size)
	{
		while (is_space(*(src + i)))
			i++;
		len = is_word(src + i);
		if (len == 0)
			len++;
		*(*ret + words) = ft_substr(src, i, len);
		if (!(*(*ret + words)))
			return (ALLOCATION_ERROR);
		i += is_word(src + i);
	}
	return (SUCCESS);
}

t_error_code	reader_split_arg(char *str, char ***ret)
{
	t_error_code	err;
	int				words;

	words = cnt_words(str);
	err = tab_create(ret, words);
	allocate_words(str, ret, words);
	return (err);
}
