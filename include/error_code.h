/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:45:15 by yoav              #+#    #+#             */
/*   Updated: 2022/10/11 13:58:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdio.h>

# include "macro.h"

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	ALLOCATION_ERROR,
	SYNTAX_ERROR,
	SYNTAX_PIPE_STILL_OPEN,
	NEW_PROC_ERROR,
}	t_error_code;

void	error_code_print(t_error_code err, void *param);

#endif
