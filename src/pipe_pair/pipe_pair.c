/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:19:40 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:19:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_pair.h"

t_error_code	pipe_pair_create(t_pipe_pair **ret)
{
	t_error_code	err;
	t_pipe_pair		*pp;

	pp = ft_calloc(1, sizeof(t_pipe_pair));
	if (!pp)
		return (ALLOCATION_ERROR);
	err = pipe_create(&(pp->in));
	if (SUCCESS != err)
	{
		free(pp);
		return (err);
	}
	err = pipe_create(&(pp->out));
	if (SUCCESS != err)
	{
		pipe_destroy(&(pp->in));
		free(pp);
		return (err);
	}
	*ret = pp;
	return (SUCCESS);
}

void	pipe_pair_destroy(t_pipe_pair **obj)
{
	t_pipe_pair	*pp;

	pp = *obj;
	if (pp->in)
		pipe_destroy(&(pp->in));
	if (pp->out)
		pipe_destroy(&(pp->out));
	ft_bzero(pp, sizeof(t_pipe_pair));
	free(pp);
	*obj = NULL;
}

t_error_code	pipe_pair_close(t_pipe_pair *pp)
{
	t_error_code	err;

	if (!pp)
		return (SUCCESS);
	if (pp->in && pp->in->on)
	{
		err = pipe_close(pp->in);
		if (SUCCESS != err)
			return (err);
	}
	if (pp->out && pp->out->on)
	{
		err = pipe_close(pp->out);
		if (SUCCESS != err)
			return (err);
	}
	return (SUCCESS);
}
