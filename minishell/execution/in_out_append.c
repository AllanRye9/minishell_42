/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:11:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_in(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg((t_err)
			{ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_RDONLY);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_read(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

int	ft_out(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg((t_err)
			{ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_write(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

int	ft_append(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg((t_err)
			{ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_CREAT | O_WRONLY | O_APPEND | 0644);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_write(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (0);
}
