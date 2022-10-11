/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2022/10/11 13:57:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define MINISHELL_NAME		"minishell"
# define SYNTAX_ERROR_MSG	"syntax error near unexpected token"
# define PIPE_CHAR			'|'
# define RR_CHAR			'>'
# define RL_CHAR			'<'
# define SEMICOLON_CHAR		';'
# define NEW_LINE_CHAR		'\n'
# define SINGLE_QUOTE_CHAR	'\''
# define DOUBLE_QUOTE_CHAR	'\"'
# define SPACE_CHAR			' '
# define IGNORE_PROMPT		"ignore_me> "
# define MAIN_PROMPT		"prompt> "
# define DQUOTE_PROMPT		"dquote> "
# define EMPTY_STRING		""
# define NEW_PROC			0

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
