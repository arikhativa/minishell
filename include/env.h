/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:51:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/23 13:35:03 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "error_code.h"
# include "tab.h"
# include "shell_op.h"
# include "env_utils.h"

# define SHLVL_KEY	"SHLVL"

char			*env_getvar(char **env, char *key);
void			env_unsetvar(char **env, char *key);
t_error_code	env_initenv(char ***env, char **envp);
t_error_code	env_setvar(char ***env, char *key, char *value);
void			env_destroy(char ***env);
t_error_code	env_inc_shlvl(char **env);

#endif
