/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:52:49 by yoav              #+#    #+#             */
/*   Updated: 2022/10/18 14:47:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# include "error_code.h"
# include "libft.h"

void			tab_print(char **input_table);
t_error_code	tab_create(char	***ret, size_t size);
void			tab_deep_destroy(char ***t);
void			tab_shallow_destroy(char ***t);
t_error_code	tab_add(char ***tab, char *s);
size_t			tab_count(char **t);

#endif
