/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:06:23 by yoav              #+#    #+#             */
/*   Updated: 2022/09/19 12:43:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_LIST_H
# define TOKEN_LIST_H

# include "token.h"
# include "error_code.h"
# include "dll.h"

typedef struct s_token_list
{
	t_dll	*tok_lst;
}	t_token_list;

t_error_code	token_list_create(t_token_list **ret);
void			token_list_destroy(t_token_list	**lst);
t_error_code	token_list_add_last(t_token_list *lst, t_token *tok);
t_dll			*token_list_get_node(t_token_list *lst);

// print
void			token_list_print(t_token_list *lst);

#endif
