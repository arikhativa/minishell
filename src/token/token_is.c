/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:05:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/22 17:07:05 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_bool	token_is_word(t_token *t)
{
	return (WORD == t->type);
}

t_bool	token_is_pipe(t_token *t)
{
	return (PIPE == t->type);
}

t_bool	token_is_redirect(t_token *t)
{
	return (REDIRECT == t->type);
}

t_bool	token_is_semi_redirect(t_token *t)
{
	return (SEMI_REDIRECT == t->type);
}

t_bool	token_is_semicolon(t_token *t)
{
	return (SEMICOLON == t->type);
}
