/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:42:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/22 16:52:54 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	valid_param(char *arg)
{
	int	i;

	i = -1;
	if (ft_isdigit(arg[0]) || arg[0] == '=' || )
		return ()
}

int	custom_export(t_sysvar *sys_var, char **argv)
{
	char	**tmp;
	int		i;

	i = -1;
	if (argv[1] || argv[1][0] == '\0')
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
