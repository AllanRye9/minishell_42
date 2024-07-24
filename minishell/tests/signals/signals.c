#include "minishell.h"

static void	ft_sigint_handler(int num)
{
	(void)num;
	if (G_shell_.signint_child)
	{
		ft_putstr_fd("\n", 1);
		G_shell_.signint_child = false;
		G_shell_.heredoc_sigint = true;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

void	signal_init_(void)
{
	struct termios	term;

	term = G_shell_.original_terminal;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	G_shell_.heredoc_sigint = false;
	G_shell_.signint_child = false;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
