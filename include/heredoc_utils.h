/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:13:42 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 06:14:19 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_UTILS_H
# define HEREDOC_UTILS_H

void			heredoc_tab_add_heredoc(char ***heredoc_tab, char *value);
void			heredoc_tab_destroy(char ***heredoc_tab);

#endif
