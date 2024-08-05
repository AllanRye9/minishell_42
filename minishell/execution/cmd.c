/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:59:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/04 16:42:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_reset_stds(bool piped, t_minishell *g_shell)
{
	if (piped)
		return ;
	dup2(g_shell->stdin, 0);
	dup2(g_shell->stdout, 0); //might be error here the stdin is standard stdin
}

int	ft_redirection(t_node *node)
{
	t_io_node	*io;
	int			status;

	io = node->io_list;
	while (io)
	{
		if (io->type == IO_OUT
			&& ft_out(io, &status) != ENO_SUCCESS)
			return (status);
		else if (io->type == IO_IN
			&& ft_in(io, &status) != ENO_SUCCESS)
			return (status);
		else if (io->type == IO_APPEND
			&& ft_append(io, &status) != ENO_SUCCESS)
			return (status);
		else if (io->type == IO_HEREDOC)
			(dup2(io->here_doc, 0), close(io->here_doc));
		io = io->next;
	}
	return (ENO_SUCCESS);
}

static int	ft_exec_child(t_node *node, t_minishell *g_shell)
{
	t_path	path_status;
	int		status;
	int		fork_pid;

	g_sig_handler.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		status = ft_redirection(node);
		if (status != ENO_SUCCESS)
			(ft_clean(g_shell), exit(ENO_GENERAL));
		path_status = ft_get_path((node->expanded_args)[0], g_shell);
		if (path_status.err.no != ENO_SUCCESS)
		{
			status = ft_err_msg(path_status.err);
			(ft_clean(g_shell), exit(status));
		}
		if (execve(path_status.path, node->expanded_args, g_shell->environ) == -1)
			(ft_clean(g_shell), exit(1));
	}
	waitpid(fork_pid, &status, 0);
	g_sig_handler.signint_child = false;
	return (ft_get_exitstatus(status));
}

int	ft_exec_cmd(t_node *node, bool piped, t_minishell *g_shell)
{
	int	status;

	if (!node->expanded_args)
	{
		status = ft_redirection(node);
		return (ft_reset_stds(piped, g_shell), (status && ENO_GENERAL));
	}
	else if (ft_is_builtin((node->expanded_args)[0]))
	{
		status = ft_redirection(node);
		if (status != ENO_SUCCESS)
			return (ft_reset_stds(piped, g_shell), ENO_GENERAL);
		status = ft_exec_builtin(node->expanded_args, g_shell);
		return (ft_reset_stds(piped, g_shell), status);
	}
	else
		return (ft_exec_child(node, g_shell));
}
