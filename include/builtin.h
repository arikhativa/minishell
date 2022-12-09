/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:16 by yoav              #+#    #+#             */
/*   Updated: 2022/12/08 17:04:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "macro.h"
# include "shell_op.h"
# include "error_code.h"
# include "libft.h"
# include "expander.h"
# include "cmd.h"
# include "tab.h"
# include "env.h"
# include "mini_util.h"

# define BUILTIN_ECHO_STR	"echo"
# define BUILTIN_CD_STR		"cd"
# define BUILTIN_PWD_STR	"pwd"
# define BUILTIN_EXPORT_STR	"export"
# define BUILTIN_UNSET_STR	"unset"
# define BUILTIN_ENV_STR	"env"
# define BUILTIN_EXIT_STR	"exit"
# define EXIT_NUM_ERR_VALUE	255

typedef t_error_code	(*t_builtin)(t_shell_op *sp, t_cmd *c);

t_bool			is_builtin(char *word);
t_builtin		builtin_get_func(char *word);
t_error_code	builtin_no_builtin(t_shell_op *sp, t_cmd *c);

t_error_code	builtin_echo(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_cd(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_pwd(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_export(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_unset(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_env(t_shell_op *sp, t_cmd *c);
t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c);

// export util
void			print_key_and_value(char *s, int fd);
t_bool			export_is_input_valid(char *s);
t_bool			export_should_ignore_input(char *s);
t_error_code	export_print_all(char **tab, int fd);

#endif
