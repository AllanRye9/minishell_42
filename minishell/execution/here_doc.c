/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:23 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	heredoc_sigint(int sig)
{
	(void)sig;
	g_sig_handler.cleanup_needed = true;
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int fd[2], t_minishell *g_shell)
{
	char	*line;
	char	*quote;

	signal(SIGINT, heredoc_sigint);
	if (g_sig_handler.cleanup_needed)
		ft_clean(g_shell);
	quote = io->value;
	while (*quote && *quote != '"' && *quote != '\'')
		quote++;
	while (1)
	{
		line = readline("> ");
		if (!line || is_delimeter(io->value, line))
			break ;
		if (!*quote)
			ft_heredoc_expander(line, fd[1], g_shell);
		else
			ft_putendl_fd(line, fd[1]);
		free(line);
	}
	exit(0);
}
