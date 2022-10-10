/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2022/09/24 13:33:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define PIPE_CHAR			'|'
# define RR_CHAR			'>'
# define RL_CHAR			'<'
# define SEMICOLON_CHAR		';'
# define NEW_LINE_CHAR		'\n'
# define SINGLE_QUOTE_CHAR	'\''
# define DOUBLE_QUOTE_CHAR	'\"'
# define NEW_PROC			0

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
