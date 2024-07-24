/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:28:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/23 12:05:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**del_loop(char **env, char **ret_strings, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		if (!(ft_strncmp(env[i], argv, after_eql_sign(env[i]) - 1) == 0
				&& argv[after_eql_sign(env[i])] == '\0'
				&& env[i][ft_strlen(argv)] == '='))
		{
			ret_strings = ft_strdup(env[i]);
			if (ret_strings[j] == NULL)
			{
				free_doublearr(ret_strings);
				return (ret_strings);
			}
			j++;
		}
		i++;
	}
	return (ret_strings);
}

char	**del_var(char **env, char *argv)
{
	char	**ret_strings;
	int		i;

	i = 0;
	while (env[i] != NULL)
		i++;
	ret_strings = ft_calloc(sizeof(char *), i + 1);
	if (!ret_strings)
		return (NULL);
	ret_strings = del_loop(env, ret_strings, argv);
}

int	error_in_unset(char **args)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (args[1][i])
	{
		if (args[1][i] == '/')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	if (after_eql_sign(args[1] != 0))
	{
		ft_putendl_fd("minishell: unset: not a valid identifier", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	unset(t_sysvar *sys_var, char **args)
{
	char	**tmp;

	if (error_in_unset(args) == 1)
		return (EXIT_FAILURE);
	else
	{
		tmp = del_var(sys_var->env, args[1]);
		free_doublearr(sys_var->env);
		sys_var->env = tmp;
	}
	return (EXIT_SUCCESS);
}
