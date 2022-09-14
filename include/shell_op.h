/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:31:58 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 10:05:35 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_OP_H
# define SHELL_OP_H

# include "error_code.h"
# include "libft.h"
# include "tab.h"
# include "token_list.h"

typedef struct s_shell_op
{
	char			**input;
	t_token_list	*token_list;
}	t_shell_op;

t_error_code	shell_op_create(t_shell_op **ret);
void			shell_op_destroy(t_shell_op **sp);
void			shell_op_set_token_list(t_shell_op *sp, t_token_list *tok_lst);
void			shell_op_set_input(t_shell_op *sp, char **input);

#endif
