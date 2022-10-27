/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/25 14:50:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static t_bool	is_quote_closed(char *str)
{
	char	quote_char;
	size_t	i;

	i = 1;
	quote_char = *str;
	while ((*(str + i) && *(str + i) != quote_char))
		i++;
	if (*(str + i) == quote_char)
		return (i);
	return (0);
}

static t_error_code	close_opened_quote(char **line)
{
	char	*tmp;
	char	*new_content;
	size_t	i;

	i = -1;
	while (*(*line + ++i))
	{
		if (reader_is_squote(*(*line + i)) || reader_is_dquote(*(*line + i)))
		{
			while (!is_quote_closed(*line + i))
			{
				tmp = *line;
				new_content = readline(reader_get_quote_prompt(*(*line + i)));
				if (!new_content)
					return (ERROR);
				*line = ft_strjoin(*line, new_content);
				free(tmp);
				if (!(*line))
					return (ALLOCATION_ERROR);
				free(new_content);
			}
			i += is_quote_closed(*line + i);
		}
	}
	return (SUCCESS);
}

t_error_code	reader_get_tab(char ***ret)
{
	t_error_code	err;
	char			*line;

	line = readline(MAIN_PROMPT);
	if (!line)
		return (ERROR);
	err = close_opened_quote(&line);
	if (SUCCESS != err)
		return (err);
	if (!line)
		return (ERROR);
	add_history(line);
	err = reader_split_by_token(line, ret);
	free(line);
	return (err);
}
