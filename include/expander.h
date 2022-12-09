/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:24:16 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/02 19:40:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdlib.h>
# include <unistd.h>

# include "reader.h"
# include "tab.h"
# include "error_code.h"
# include "shell_op.h"
# include "libft.h"
# include "macro.h"
# include "env.h"
# include "redirect_util.h"

typedef enum e_quote_stt
{
	OUT_QUOTE = 0,
	IN_QUOTE,
}	t_quote_stt;

typedef struct s_quote
{
	t_quote_stt	double_quote;
	t_quote_stt	single_quote;
	t_bool		in;
}	t_quote;

char			*expander_expand_var(t_shell_op *sp, char *str);
t_error_code	expander_remove_all_quotes(t_shell_op *sp);
char			*expander_remove_line_quotes(char *str);
char			*str_insert_char_after(char *str, char c, size_t pos);
t_bool			is_end_of_var_name(char c);
t_bool			is_valid_for_expansion(char *str);
t_bool			ready_to_expand(char *str, int i);
t_bool			is_valid_tilde(char *str, int i, t_bool in_quote);
void			update_stt(t_quote *stt, char c);
t_bool			should_expand(char *str, int i, t_bool in);

#endif
