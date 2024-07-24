#include "minishell.h"

static void	sig_handler(int code)
{
	(void)code;
	if(G_shell_.signint_child)
	{
		ft_putstr_fd("\n", 1);
		G_shell_.signint_child = false;
		G_shell_.heredoc_sigint = true;
	}
	else
	{
		ft_putchar_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void ft_sigquit_handler(int code)
{
	(void)code;
	ft_putchar_fd("Quit: 3\n", 1);
}

void signal_init_(void)
{
	struct termios t;

	t = G_shell_.orignal_terminal;
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
	G_shell_.heredoc_sigint = false;
	G_shell_.signint_child = false;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
