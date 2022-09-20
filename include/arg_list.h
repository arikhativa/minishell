/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:54 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 15:56:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_LIST_H
# define ARG_LIST_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "dll.h"

typedef struct s_arg_list
{
	int		size;
	t_dll	*lst;
}	t_arg_list;

t_error_code	arg_list_create(t_arg_list **ret);
void			arg_list_destroy(t_arg_list **l);
t_error_code	arg_list_add_last(t_arg_list *lst, char *arg);

#endif
