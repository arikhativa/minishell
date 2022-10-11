/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:52:49 by yoav              #+#    #+#             */
/*   Updated: 2022/10/10 14:56:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include <stddef.h>
# include <stdlib.h>

# include "error_code.h"
# include "libft.h"

t_error_code	tab_create(char	***ret, size_t size);
void			tab_deep_destroy(char ***t);
void			tab_shallow_destroy(char ***t);
t_error_code	tab_add(char ***tab, char *s);
void			tab_print(char **t);

#endif
