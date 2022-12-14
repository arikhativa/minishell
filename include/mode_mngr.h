/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_mngr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:46:11 by yoav              #+#    #+#             */
/*   Updated: 2022/12/13 12:11:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_MNGR_H
# define MODE_MNGR_H

# include <unistd.h>

# include "libft.h"
# include "macro.h"

t_bool	mode_mngr_is_cli(int argc, char **argv);
t_bool	mode_mngr_is_file(int argc);
t_bool	mode_mngr_is_interactive(void);

#endif
