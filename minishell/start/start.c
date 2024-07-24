/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/24 10:04:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_environment(char **env, t_sysvar *sys_var)
{
	ft_memset(sys_var, 0, sizeof(t_sysvar));
	sys_var->env = env;
	ft_init_env();
	sys_var->stdin = dup(0);
	sys_var->stdout = dup(1);
	get_attribute(STDIN_FILENO, sys_var.original_term);  //need to work here no original term declared yet.
}

static void	ft_exec(t_sysvar *sys_var)
{
	signal(SIGQUIT, sigquit_handler);
	ft_init_tree(sys_var->node);
	if (sys_var->heredoc_sigint)
	{
		ft_clear_node(sys_var->node);
		sys_var->heredoc_sigint = false;
	}
	set_attribute(STDIN_FILENO, 2, sys_var.orignal_term);
	sys_var->exit_status = ft_exec_node(sys_var->node, false);
	ft_clear_node(sys_var->node);
}


int main(int argc, char **argv, char **env) {
    t_sysvar sys_var;

    (void)argc;
    (void)argv;
    init_environment(env, &sys_var);
    while (1)
	{
        init_signals();
        sys_var.args = readline(PROMPT_MSG);
        if (!sys_var.args)
		{
            ft_clean();
            ft_putstr_fd("exit\n", STDOUT_FILENO);
            exit(sys_var.exit_status);
        }
        if (sys_var.args[0])
            add_history(sys_var.args);
        sys_var.tokens = ft_token();
        if (sys_var.tokens)
		{
            sys_var.node = ft_parsing();
            if (!sys_var.parsing_error.error_type)
                ft_exec(&sys_var);
            else
                ft_handle_error();
        }
    }
    return (ft_clean(), sys_var.exit_status);
}
