/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:28:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/20 16:44:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

t_error_code	reader_get_tab_from_cli(t_shell_op *sp)
{
	t_error_code	err;

	if (!sp->cli_input)
		return (EOF_SUCCESS);
	err = reader_split_by_token(sp->cli_input, &(sp->input));
	sp->cli_input = NULL;
	return (err);
}
