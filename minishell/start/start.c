/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 09:27:28 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_environment(char **env, t_minishell *g_shell)
{
	ft_memset(g_shell, 0, sizeof(t_minishell));
	g_shell->environ = env;
	ft_init_envlst(g_shell);
	g_shell->stdin = dup(0);
	g_shell->stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_sig_handler.original_term);
}

static void	ft_exec(t_minishell *g_shell)
{
	signal(SIGQUIT, sigquit_handler);
	printf("AST reached\n");
	init_asttree(g_shell->ast, g_shell);
	if (g_sig_handler.heredoc_sgint)
	{
		ft_clear_astree(&g_shell->ast, g_shell);
		g_sig_handler.heredoc_sgint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sig_handler.original_term);
	g_shell->exit_s = ft_exec_node(g_shell->ast, false, g_shell);
	ft_clear_astree(&g_shell->ast, g_shell);
}

int main(int argc, char **argv, char **env)
{
    t_minishell g_shell;

    (void)argc;
    (void)argv;
    init_environment(env, &g_shell);
    while (1)
	{
        init_signals();
        g_shell.line = readline(PROMPT_MSG);
        if (!g_shell.line)
		{
            ft_clean(&g_shell);
            ft_putstr_fd("exit\n", STDOUT_FILENO);
            exit(g_shell.exit_s);
        }
        if (g_shell.line[0])
            add_history(g_shell.line);
        g_shell.tokens = ft_tokenize(&g_shell);
        if (g_shell.tokens)
		{
			printf("Reached on parsing\n");
            g_shell.ast = ft_parse(&g_shell);
            if (!g_shell.parse_err.type)
			{
				printf("Parsing is done and no error occured\n");
				ft_exec(&g_shell);
			}
            else
                ft_handle_parse_err(&g_shell);
        }
    }
    return (ft_clean(&g_shell), g_shell.exit_s);
}
