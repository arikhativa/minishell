/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:20:48 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 15:39:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAXER_H
# define LAXER_H

# include "shell_op.h"
# include "error_code.h"
# include "token.h"
# include "redirect_util.h"
# include "macro.h"
# include "token_list.h"

t_token_type	laxer_get_token_type(char *s);
t_error_code	laxer_create_token(t_token_list *tok_lst, char *s);
t_error_code	laxer_create_token_list(t_shell_op *sp);

#endif
