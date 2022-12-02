/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:45:15 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 16:49:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "macro.h"
# include "libft.h"

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	NO_BUILTIN_ERROR,
	ALLOCATION_ERROR,
	SYNTAX_ERROR,
	SYNTAX_PIPE_STILL_OPEN,
	NEW_PROC_ERROR,
	EOF_SUCCESS,
	NO_INPUT,
	SIGNAL_ERROR,
	OPEN_ERROR,
	END_OF_TRANSMISSION,
	CLOSE_ERROR,
}	t_error_code;

t_error_code	error_code_print_internal_err(t_error_code err);
void			error_code_print(int size, ...);

#endif
