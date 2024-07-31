/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 11:04:19 by sbartoul         ###   ########.fr       */
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
	tcgetattr(STDIN_FILENO, g_shell.original_term);
}

static void	ft_exec(t_minishell *g_shell)
{
	signal(SIGQUIT, sigquit_handler);
	ft_init_tree(g_shell->ast, g_shell);
	if (g_sig_handler.heredoc_sigint)
	{
		ft_clear_node(g_shell->ast);
		g_shell->heredoc_sigint = false;
	}
	set_attribute(STDIN_FILENO, 2, g_shell.orignal_term);
	g_shell->exit_status = ft_exec_node(g_shell->ast, false);
	ft_clear_node(g_shell->ast);
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
        g_shell.args = readline(PROMPT_MSG);
        if (!g_shell.args)
		{
            ft_clean();
            ft_putstr_fd("exit\n", STDOUT_FILENO);
            exit(g_shell.exit_status);
        }
        if (g_shell.args[0])
            add_history(g_shell.args);
        g_shell.tokens = ft_token();
        if (g_shell.tokens)
		{
            g_shell.ast = ft_parsing();
            if (!g_shell.parsing_error.error_type)
                ft_exec(&g_shell);
            else
                ft_handle_error();
        }
    }
    return (ft_clean(), g_shell.exit_status);
}
