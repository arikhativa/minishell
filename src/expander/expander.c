/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/01 10:58:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*str_append_char(char **str, char c, t_bool sufix)
{
	char	*ret;
	char	*app;

	app = (char *)malloc(sizeof(char) * 2);
	*app = c;
	*(app + 1) = 0;
	if (sufix)
		ret = ft_strjoin(*str, app);
	else
		ret = ft_strjoin(app, *str);
	free(*str);
	free(app);
	return (ret);
}

static char	*word_encloser(char *str)
{
	char	*first_part;
	char	*last_part;
	char	*final_ret;

	if (!ft_strchr(str, ' '))
		return (ft_strdup(str));
	first_part = ft_substr(str, 0, ft_strchr(str, ' ') - str);
	first_part = str_append_char(&first_part, SPACE_CHAR, TRUE);
	last_part = ft_substr(str, ft_strchr(str, ' ') - str + 1, ft_strlen(str));
	last_part = str_append_char(&last_part, DOUBLE_QUOTE_CHAR, FALSE);
	last_part = str_append_char(&last_part, DOUBLE_QUOTE_CHAR, TRUE);
	final_ret = ft_strjoin(first_part, last_part);
	free(first_part);
	free(last_part);
	return (final_ret);
}

static int	expander_get_var(t_shell_op *sp, char *str, char **ret)
{
	int		i;
	int		str_len;

	i = -1;
	str_len = ft_strlen(str);
	if (QUESTION_MARK_CHAR == *(str + 1))
	{
		*ret = ft_itoa(sp->last_cmd_stt);
		return (1);
	}
	while (++i <= str_len)
	{
		if (is_end_of_var_name(*(str + i)))
		{
			str = ft_substr(str, 1, i - 1);
			*ret = env_getvar(sp->envp, str);
			free(str);
			if (!*ret)
				*ret = EMPTY_STRING;
			if (i == 1)
				*ret = EXPANDER_STRING;
			return (i - 1);
		}
	}
	return (0);
}

static	t_bool	inside_quote(t_bool flag, char c)
{
	if (c == SINGLE_QUOTE_CHAR)
		return (!flag);
	return (flag);
}

char	*expander_expand_var(t_shell_op *sp, char *str)
{
	char	*ret;
	char	*exp;
	char	*tmp;
	int		i;
	t_bool	f;

	f = TRUE;
	i = -1;
	ret = ft_strdup(EMPTY_STRING);
	while (*(str + ++i) && (sp->envp))
	{
		f = inside_quote(f, *(str + i));
		tmp = ret;
		if (EXPANDER_CHAR == *(str + i) && f && !ready_to_expand(str, i - 1))
		{
			i += expander_get_var(sp, str + i, &exp);
			exp = word_encloser(exp);
			ret = ft_strjoin(tmp, exp);
			free(exp);
			free(tmp);
		}
		else
			ret = str_append_char(&ret, *(str + i), 1);
	}
	return (ret);
}
