/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:16 by yoav              #+#    #+#             */
/*   Updated: 2022/10/18 14:48:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "macro.h"
# include "shell_op.h"
# include "error_code.h"
# include "libft.h"
# include "cmd.h"

# define NO_BUILTIN_ERROR	"unknown built-in"
# define BUILTIN_EXIT_STR	"exit"

typedef t_error_code	(*t_builtin)(t_shell_op *sp, t_cmd *c);

t_bool			is_builtin(char *word);
t_builtin		builtin_get_func(char *word);
t_error_code	builtin_no_builtin(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c);

#endif
