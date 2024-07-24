#include "minishell.h"

static void	ft_heredoc_sigint_handler(int signum)
{
	(void)signum;
	ft_clean();
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int p[2])
{
	char	*line;
	char	*quotes;

	signal(SIGINT, ft_heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_is_delimiter(io->value, line))
			break ;
		if (!*quotes)
			ft_heredoc_expander(line, p[1]);
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	ft_clean();
	exit(0);
}

static bool	ft_leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	G_shell_.signint_child = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

static void	ft_init_leaf(t_node *node)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args);
	io = node->io_list;
	while (io)
	{
		if (io->type == _HEREDOC)
		{
			pipe(p);
			G_shell_.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p);
			if (ft_leave_leaf(p, &pid))
				return ;
			io->here_doc = p[0];
		}
		else
			io->expanded_value = ft_expand(io->value);
		io = io->next;
	}
}

void	ft_init_tree(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_PIPE
		|| node->type == N_AND
		|| node->type == N_OR)
	{
		ft_init_tree(node->left);
		if (!G_shell_.heredoc_sigint)
			ft_init_tree(node -> right);
	}
	else
		ft_init_leaf(node);
}