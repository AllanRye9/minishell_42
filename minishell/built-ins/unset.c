/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:28:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/22 22:10:12 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_key(char *args)
{
	int	i;

	i = -1;
	if (!ft_isalpha(*args) && *args != '_')
		return (0);
	while (args[i] && args[i] != '=')
	{
		if (!ft_isalnum(args[i]) && args[i] != '_')
			return (0);
	}
	return (1);
}

int	unset(t_sysvar *sys_var, char **args)
{
	int	i;
	int	ret_val;

	i = 1;
	if (!args[1])
		return (0);
	ret_val = 0;
	while (args[i])
	{
		if (!check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
			ret_val = 1;
		}
		else
		{
			if (unsetenv(args[i]) != 0)
			{
				ft_putstr_fd("minishell: unset error clearing variables", STDERR_FILENO);
				ft_putendl_fd(args[i], 2);
				ret_val = 1;
			}
		}
		i++;
	}
	return (ret_val);
}
