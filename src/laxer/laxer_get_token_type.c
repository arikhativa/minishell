/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer_get_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:33:28 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 11:57:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laxer.h"

static t_bool	is_pipe(char *s)
{
	return (PIPE_CHAR == *s);
}

static t_bool	is_semicolon(char *s)
{
	return (SEMICOLON_CHAR == *s);
}

static t_bool	is_new_line(char *s)
{
	return (NEW_LINE_CHAR == *s);
}

static t_bool	is_string(char *s)
{
	return (SINGLE_QUOTE_CHAR == *s || DOUBLE_QUOTE_CHAR == *s);
}

t_token_type	laxer_get_token_type(char *s)
{
	if (is_string(s))
		return (WORD);
	else if (is_pipe(s))
		return (PIPE);
	else if (is_new_line(s))
		return (NEW_LINE);
	else if (is_semicolon(s))
		return (SEMICOLON);
	else if (is_redirect(s))
	{
		if (is_semi_redirect(s))
			return (SEMI_REDIRECT);
		return (REDIRECT);
	}
	return (WORD);
}
