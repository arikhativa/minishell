/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:26:18 by yoav              #+#    #+#             */
/*   Updated: 2022/10/23 13:19:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SIGNAL_H
# define MINI_SIGNAL_H

# include <stdio.h>
# include <readline/readline.h>
# include <signal.h>

# include "macro.h"
# include "error_code.h"

t_error_code	mini_signal_interactive_mode(void);
t_error_code	mini_signal_disable(void);

#endif
