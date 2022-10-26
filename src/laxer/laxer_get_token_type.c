/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer_get_token_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:33:28 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:07:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laxer.h"

static t_bool	is_pipe(char *s)
{
	return (PIPE_CHAR == *s);
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
	else if (is_redirect(s))
		return (REDIRECT);
	return (WORD);
}
