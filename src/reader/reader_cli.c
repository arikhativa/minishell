/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:28:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/02 12:27:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

t_error_code	reader_get_tab_from_cli(t_shell_op *sp)
{
	t_error_code	err;

	if (!sp->cli_input)
		return (EOF_SUCCESS);
	sp->cli_input = expander_expand_var(sp, sp->cli_input);
	err = reader_split_by_token(sp->cli_input, &(sp->input));
	sp->cli_input = NULL;
	return (err);
}
