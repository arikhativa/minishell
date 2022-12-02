/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:09:28 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 10:28:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANER_H
# define CLEANER_H

# include "tab.h"
# include "token_list.h"
# include "cmd_list.h"
# include "shell_op.h"

void	cleaner_round_clean(t_shell_op *sp);
void	cleaner_on_pipe_error(t_shell_op *sp);

#endif
