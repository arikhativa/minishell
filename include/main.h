/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:19:46 by yoav              #+#    #+#             */
/*   Updated: 2022/10/23 00:12:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <fcntl.h>

# include "error_code.h"
# include "macro.h"
# include "executer.h"
# include "commander.h"
# include "parser.h"
# include "laxer.h"
# include "shell_op.h"
# include "mini_signal.h"
# include "reader.h"
# include "cleaner.h"

typedef t_error_code	(*t_read_input)(char ***tab);

#endif
