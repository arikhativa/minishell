/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:25:38 by yoav              #+#    #+#             */
/*   Updated: 2022/12/09 11:26:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "macro.h"
# include "error_code.h"
# include "shell_op.h"
# include "cmd_list.h"

t_error_code	parser_check_tokens(t_shell_op *sp);
t_error_code	is_token_valid(t_dll *node, int *skip);
t_dll			*get_next_node(t_dll *node, int i);

#endif
