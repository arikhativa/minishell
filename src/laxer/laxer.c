/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:20:42 by yoav              #+#    #+#             */
/*   Updated: 2022/09/17 12:33:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laxer.h"

t_error_code	laxer_create_token(t_token_list *tok_lst, char *s)
{
	t_error_code	err;
	t_token_type	type;
	t_token			*tok;

	type = laxer_get_token_type(s);
	err = token_create(&tok, s, type);
	if (SUCCESS != err)
		return (err);
	err = token_list_add_last(tok_lst, tok);
	if (SUCCESS != err)
	{
		token_destroy(&tok);
		return (err);
	}
	return (err);
}

t_error_code	laxer_create_token_list(t_shell_op *sp)
{
	t_error_code	err;
	int				i;

	err = token_list_create(&(sp->token_list));
	if (SUCCESS != err)
		return (err);
	i = 0;
	while (sp->input[i])
	{
		err = laxer_create_token(sp->token_list, sp->input[i]);
		if (SUCCESS != err)
		{
			token_list_destroy(&(sp->token_list));
			return (err);
		}
		++i;
	}
	return (SUCCESS);
}
