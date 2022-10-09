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

t_error_code	reader_split_arg(char *str, char ***ret);
t_error_code	reader_from_arg(int argc, char **argv);
t_error_code	reader(char ***ret);
int            	is_special(char *str);
t_bool      	is_dquote(char c);
t_bool      	is_squote(char c);
t_bool      	is_space(char c);


t_bool			quote_is_closed(char *str);
int				cnt_words(char *str);
t_error_code	allocate_words(char *src, char ***ret, int size);

#endif
