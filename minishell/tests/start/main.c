#include "minishell.h"

t_minishell	G_shell_;

static void	ft_init_minishell(char **env)
{
	ft_memset(&G_shell_, 0, sizeof(t_minishell));
	G_shell_.environ = env;
	ft_init_envlst();
	G_shell_.stdin = dup(0);
	G_shell_.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &G_shell_.original_terminal);
}

static void	initialize_execution(void)
{
	signal(SIGQUIT, ft_sigquit_handler);
	ft_init_tree(G_shell_.ast);
	if (G_shell_.heredoc_sigint)
	{
		ft_clear_ast(&G_shell_.ast);
		G_shell_.heredoc_sigint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &G_shell_.original_terminal);
	G_shell_.exit_s = ft_exec_node(G_shell_.ast, false);
	ft_clear_ast(&G_shell_.ast);
}

int	main(int argc, char **argv, char **env)
{
	((void)argc, (void)argv);
	ft_init_minishell(env);
	while (1)
	{
		signal_init_();
		G_shell_.line = readline(PROMPT);
		if (!G_shell_.line)
			(ft_clean(),
				ft_putstr_fd("exit\n", 1), exit(G_shell_.exit_s));
		if (G_shell_.line[0])
			add_history(G_shell_.line);
		G_shell_.tokens = ft_tokenize();
		if (!G_shell_.tokens)
			continue ;
		G_shell_.ast = ft_parse();
		if (G_shell_.parse_err.type)
		{
			handle_parsing_err();
			continue ;
		}
		initialize_execution();
	}
	clear_data(NULL, true);
	return (ft_clean(), G_shell_.exit_s);
}
