/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:43:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:20:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}

int	ft_exec_builtin(char **args, t_minishell *g_shell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(g_shell, args[1]));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(g_shell, args));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(g_shell, args));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(g_shell));
	ft_exit(g_shell, args);
	return (ENO_GENERAL);
}
