/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:53:00 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/06 18:04:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	ft_exit_leaf(int fd[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, sigquit_handler);
	g_sig_handler.signint_child = false;
	close(fd[1]);
	if (WIFEXITED(*pid) && (WEXITSTATUS(*pid) == SIGINT))
		return (true);
	return (false);
}

static void	init_leaf(t_node *node, t_minishell *g_shell)
{
	t_io_node	*io;
	int			fd[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args, g_shell);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(fd);
			g_sig_handler.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, fd, g_shell);
			if (ft_exit_leaf(fd, &pid))
				return;
			io->here_doc = fd[0];
		}
		else
			io->expanded_value = ft_expand(io->value, g_shell);
		io = io->next;
	}
}

void	init_asttree(t_node *node, t_minishell *g_shell)
{
	if (!node)
		return ;
	if (node->type == N_PIPE || node->type == N_AND || node->type == N_OR)
	{
		init_asttree(node->left, g_shell);
		if (!g_sig_handler.heredoc_sgint)
			init_asttree(node->right, g_shell);
	}
	else
		init_leaf(node, g_shell);
}
