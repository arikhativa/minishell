/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:58:41 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 15:59:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUP_WRAPPER_H
# define DUP_WRAPPER_H

# include <unistd.h>

# include "error_code.h"

t_error_code	dup_wrapper(int oldfd, int newfd);

#endif
