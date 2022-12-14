/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/12 12:51:16 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*heredoc_readline(char *eol)
{
	char	*ret;

	ret = readline(HEREDOC_PROMPT);
	if (!ret)
		ret = ft_strdup(eol);
	return (ret);
}

void	heredoc_line(char **line, char *eol)
{
	char	*str;
	char	*tmp;

	if (!eol)
		return ;
	str = heredoc_readline(eol);
	*line = ft_strdup("");
	while (ft_strcmp(str, eol))
	{
		tmp = *line;
		*line = ft_strjoin(*line, str);
		free(tmp);
		free(str);
		tmp = *line;
		*line = ft_strjoin(*line, "\n");
		free(tmp);
		str = heredoc_readline(eol);
	}
	free(str);
}

void	heredoc_tab_destroy(char ***heredoc_tab)
{
	tab_shallow_destroy(heredoc_tab);
}

char	*heredoc_get_temp_path(char *base_path)
{
	char	*path;
	char	*aux;
	int		n;

	n = 0;
	aux = ft_itoa(n);
	path = ft_strjoin(base_path, aux);
	free(aux);
	while (0 == access(path, F_OK))
	{
		n++;
		free(path);
		aux = ft_itoa(n);
		path = ft_strjoin(base_path, aux);
		free(aux);
	}
	return (path);
}

void	heredoc_handle_heredoc(t_redirect *r)
{
	char	*line;
	int		fd;

	fd = open(r->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	heredoc_line(&line, r->heredoc_eol);
	write(fd, line, ft_strlen(line));
	close(fd);
	free(line);
}
