/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:35:29 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 11:01:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdlib.h>

# include "error_code.h"
# include "libft.h"

typedef enum e_token_type
{
	WORD,
	OPERATOR,	
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

t_error_code	token_create(t_token **ret, char *ptr, t_token_type type);
void			token_destroy(t_token **t);

#endif
