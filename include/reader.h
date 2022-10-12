/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:21:18 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/25 14:50:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "error_code.h"
# include "libft.h"
# include "tab.h"
# include "macro.h"

t_error_code	reader_split_by_token(char *str, char ***ret);
t_error_code	reader_get_tab(char ***ret);
t_bool			reader_is_special(char *str);
t_bool      	reader_is_dquote(char c);
t_bool      	reader_is_squote(char c);
t_bool      	reader_is_space(char c);
char			*reader_get_quote_prompt(char c);

#endif
