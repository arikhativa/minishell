/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:05:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/22 17:10:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_bool	token_is_word_or_redirect(t_token *t)
{
	return (token_is_word(t) || token_is_redirect(t));
}

t_bool	token_is_new_line(t_token *t)
{
	return (NEW_LINE == t->type);
}

t_bool	token_is_break(t_token *t)
{
	return (token_is_new_line(t) || token_is_semicolon(t));
}
