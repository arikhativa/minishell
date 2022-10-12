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

static t_bool	check_inside_quote(char c, char del)
{
	return ((reader_is_dquote(c)
			&& c != del
			&& !reader_is_squote(del))
		|| (reader_is_squote(c)
			&& c != del
			&& !reader_is_dquote(del)));
}

static int	get_word(char *str)
{
	char	del;
	size_t	i;

	if (!*str)
		return (0);
	i = reader_is_special(str);
	if (i)
		return (i);
	else
		i = -1;
	del = SPACE_CHAR;
	while (*(str + ++i) && *(str + i) != del)
	{
		if (reader_is_space(del) && reader_is_special(str + i))
			return (i);
		if (check_inside_quote(*(str + i), del))
			del = *(str + i);
		if (!reader_is_space(del) && *(str + i + 1) == del)
		{
			del = SPACE_CHAR;
			i += 1;
		}
	}
	return (i + 1 + (reader_is_dquote(del) || reader_is_squote(del))
		- reader_is_space(*(str + i)));
}

static size_t	cnt_words(char *str)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (*(str + i))
	{
		while (reader_is_space(*(str + i)) && *(str + i))
			i++;
		i += get_word(str + i);
		if (i > ft_strlen(str))
			i--;
		words++;
		while (reader_is_space(*(str + i)) && *(str + i))
			i++;
	}
	return (words);
}

static t_error_code	allocate_words(char *src, char ***ret, int size)
{
	int		words;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	words = -1;
	while (++words < size)
	{
		while (reader_is_space(*(src + i)))
			i++;
		len = get_word(src + i);
		if (len == 0)
			len++;
		*(*ret + words) = ft_substr(src, i, len);
		if (!(*(*ret + words)))
			return (ALLOCATION_ERROR);
		i += get_word(src + i);
	}
	*(*ret + words) = NULL;
	return (SUCCESS);
}

t_error_code	reader_split_by_token(char *str, char ***ret)
{
	t_error_code	err;
	size_t			words;

	words = cnt_words(str);
	err = tab_create(ret, words);
	allocate_words(str, ret, words);
	return (err);
}
