/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:35:29 by yoav              #+#    #+#             */
/*   Updated: 2022/09/22 17:10:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdio.h>
# include <stdlib.h>

# include "macro.h"
# include "error_code.h"
# include "libft.h"

typedef enum e_token_type
{
	WORD,
	SEMICOLON,
	PIPE,
	NEW_LINE,
	REDIRECT,
	SEMI_REDIRECT,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

t_error_code	token_create(t_token **ret, char *ptr, t_token_type type);
void			token_destroy(t_token **t);

// print
void			token_print(t_token *t);

// is
t_bool			token_is_word(t_token *t);
t_bool			token_is_pipe(t_token *t);
t_bool			token_is_redirect(t_token *t);
t_bool			token_is_semi_redirect(t_token *t);
t_bool			token_is_semicolon(t_token *t);
t_bool			token_is_word_or_redirect(t_token *t);
t_bool			token_is_new_line(t_token *t);
t_bool			token_is_break(t_token *t);

#endif
