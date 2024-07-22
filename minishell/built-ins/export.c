/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:42:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/22 19:44:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	equalsign_exist(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] == '=')
			return (i + 1);
	return (0);
}

int	valid_param(char *arg)
{
	int	i;

	i = -1;
	if (ft_isdigit(arg[0]) || arg[0] == '=' || !equalsign_exist(arg))
		return (error_in_export(arg));
	while (arg[++i] != '=')
		if (invalid_id(arg[i]))
			return (error_in_export(arg));
	return (EXIT_SUCCESS);
}

int	variable_exist(t_sysvar *sys_var, char *argv)
{
	int	i;

	i = 0;
	while (argv[after_eql_sign(argv)] == '\"' && i < 2)
	{
		delete_quotes(argv, '\"');
		i++;
	}
	i = -1;
	while (sys_var->env[++i])
	{
		if (ft_strncmp(sys_var->env[i], argv, after_eql_sign(sys_var->env[i])) == 0)
		{
			free(sys_var->env[i]);
			sys_var->env[i] = ft_strdup(argv);
			return (1);
		}
	}
	return (0);
}

int	custom_export(t_sysvar *sys_var, char **argv)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!argv[1] || argv[1][0] == '\0')
		env(sys_var);
	else
	{
		while (argv[i])
		{
			if (valid_param(argv[i]) && variable_exist(sys_var, argv[i]))
			{
				if (argv[i])
				{
					tmp = add_var(sys_var->env, argv[i]);
					free_doublearr(sys_var->env);
					sys_var->env = tmp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
