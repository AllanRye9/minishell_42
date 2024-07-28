#include "../include/minishell.h"

static void sigint_handler(int code)
{
	(void)code;
	if(g_sig_handler.signint_child)
	{
		ft_putstr_fd("\n", 1);
		g_sig_handler.signint_child = false;
		g_sig_handler.heredoc_sgint = true;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void sigquit_handler(int code)
{
	(void)code;
	ft_putstr_fd("Quit: 3\n", 1);
}

void init_signals(void)
{
	struct termios		term;

	term = g_sig_handler.original_term;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_sig_handler.cleanup_needed = false;
	g_sig_handler.heredoc_sgint = false;
	g_sig_handler.signint_child = false;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}
