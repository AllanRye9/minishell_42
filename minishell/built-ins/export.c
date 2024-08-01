/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:42:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/01 13:24:49 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isalpha(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalnum(*str) && *str != '-')
		return (0);
	while(str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_exportlst(t_minishell *g_shell)
{
	t_env	*envlst;
	size_t	i;

	envlst = g_shell->envlst;
	while (envlst)
	{
		if (envlst->value != NULL && (ft_strcmp(envlst->key, "_") != 0))
		{
			printf("declare -x %s=\"", envlst->key);
			i = 0;
			while (envlst->value[i])
			{
				if ((envlst->value)[i] == '$' || (envlst->value)[i] == '"')
					print("\\%c", (envlst->value)[i++]);
				else
					print("%c", (envlst->value)[i++]);
			}
			printf("\"\n");
		}
		else if (envlst->value = NULL && (ft_strcmp(envlst->key, "_") != 0))
			printf("declare -x %s\n", envlst->key);
		envlst = envlst->next;
	}
}

int	ft_export(t_minishell *g_shell, char **argv)
{
	char	*key;
	int		exit_status;
	int		i;

	i = 1;
	exit_status = 0;
	if (!argv[i])
		return (print_exportlst(g_shell), 0);
	while (argv[i])
	{
		if (ft_isalpha(argv[i]) == 0)
			exit_status = error_in_export(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (ft_env_entry_exist(key, g_shell))
				ft_update_envlst(key, ft_extract_value(argv[i]), false, g_shell);
			else
				ft_update_envlst(key, ft_extract_value(argv[i]), true, g_shell);
		}
		i++;
	}
	return (exit_status);
}
