/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:30:20 by yoav              #+#    #+#             */
/*   Updated: 2022/10/27 11:33:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTER_H
# define REDIRECTER_H

# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>

# include "open_wrapper.h"
# include "shell_op.h"
# include "redirect_util.h"
# include "cmd.h"

void			redirecter_init_redirect(t_cmd *c, char *symbol, char *path);
t_error_code	redirecter_setup_files(t_shell_op *sp);
void			redirecter_child_dup_if_needed(t_cmd *c);

#endif
