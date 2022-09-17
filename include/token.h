/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:35:29 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 10:42:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdio.h>
# include <stdlib.h>

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

#endif