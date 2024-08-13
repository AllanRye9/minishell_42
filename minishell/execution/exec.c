/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:22:43 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_exitstatus(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static void	ft_exec_child(t_node *node, int fd[2],
	t_ast_direction direction, t_minishell *g_shell)
{
	int	status;

	if (direction == TD_LEFT)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else if (direction == TD_RIGHT)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	status = ft_exec_node(node, true, g_shell);
	(ft_clean(g_shell), exit(status));
}

static int	ft_exec_pipe(t_node *tree, t_minishell *g_shell)
{
	int	status;
	int	fd[2];
	int	pid_l;
	int	pid_r;

	g_sig_handler.signint_child = true;
	pipe(fd);
	pid_l = fork();
	if (!pid_l)
		ft_exec_child(tree->left, fd, TD_LEFT, g_shell);
	else
	{
		pid_r = fork();
		if (!pid_r)
			ft_exec_child(tree->right, fd, TD_RIGHT, g_shell);
		else
		{
			(close(fd[0]), close(fd[1]), waitpid(pid_l, &status, 0),
				waitpid(pid_r, &status, 0));
			g_sig_handler.signint_child = false;
			return (ft_get_exitstatus(status));
		}
	}
	return (ENO_GENERAL);
}

int	ft_exec_node(t_node *tree, bool piped, t_minishell *g_shell)
{
	int	status;

	if (!tree)
		return (1);
	if (tree->type == N_PIPE)
		return (ft_exec_pipe(tree, g_shell));
	else if (tree->type == N_AND)
	{
		status = ft_exec_node(tree->left, false, g_shell);
		if (status == ENO_SUCCESS)
			return (ft_exec_node(tree->right, false, g_shell));
		return (status);
	}
	else if (tree->type == N_OR)
	{
		status = ft_exec_node(tree->left, false, g_shell);
		if (status == ENO_SUCCESS)
			return (status);
		return (ft_exec_node(tree->right, false, g_shell));
	}
	else
		return (ft_exec_cmd(tree, piped, g_shell));
	return (ENO_GENERAL);
}
