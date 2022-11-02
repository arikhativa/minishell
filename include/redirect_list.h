/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:26:46 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 19:50:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_LIST_H
# define REDIRECT_LIST_H

# include "error_code.h"
# include "redirect.h"
# include "dll.h"

typedef struct s_redirect_list
{
	t_dll	*lst;
}	t_redirect_list;

t_error_code	redirect_list_create(t_redirect_list **ret);
void			redirect_list_destroy(t_redirect_list **list);
t_error_code	redirect_list_add(t_redirect_list *l, char *path, \
	t_redirect_type t);
t_redirect		*redirect_list_get_last(t_redirect_list *l);

#endif
