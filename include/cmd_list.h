/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:09:28 by yoav              #+#    #+#             */
/*   Updated: 2022/10/11 10:42:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LIST_H
# define CMD_LIST_H

# include <stdlib.h>

# include "error_code.h"
# include "cmd.h"
# include "dll.h"

typedef struct s_cmd_list
{
	t_dll	*lst;
}	t_cmd_list;

t_error_code	cmd_list_create(t_cmd_list **ret);
void			cmd_list_destroy(t_cmd_list **cmd_list);
t_error_code	cmd_list_add_cmd(t_cmd_list *lst, t_cmd *c);

// get
t_dll			*cmd_list_get_list(t_cmd_list *lst);
t_dll			*cmd_list_get_next_cmd(t_dll *node);

#endif
