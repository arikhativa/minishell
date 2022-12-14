/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:23:44 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/11 16:47:26 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# include "shell_op.h"
# include "cmd.h"
# include "libft.h"
# include "dup_wrapper.h"
# include "mini_signal.h"

void			heredoc_handle_heredoc(t_redirect *r);
t_error_code	heredoc_run_child(t_redirect *r);
char			*heredoc_get_temp_path(char *base_path);

#endif
