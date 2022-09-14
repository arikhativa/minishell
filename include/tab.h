/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:52:49 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 09:24:52 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include <stddef.h>
# include <stdlib.h>

# include "error_code.h"
# include "libft.h"

t_error_code	tab_create(char	***ret, size_t size);
void	tab_destroy(char ***t);

#endif
