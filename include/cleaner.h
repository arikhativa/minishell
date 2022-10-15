/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:09:28 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:38:24 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANER_H
# define CLEANER_H

# include "tab.h"
# include "token_list.h"
# include "cmd_list.h"
# include "shell_op.h"

void	cleaner_round_clean(t_shell_op *sp);

#endif
