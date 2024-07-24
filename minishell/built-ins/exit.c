/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:35:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/21 17:48:14 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_with_code(char **args)
{
	int	exit_code;

	if (!args[1])
		exit_code = 0;
	else if (is_digit(args[1]))
		exit_code = ft_atoi(args[1]);
	else
	{
		ft_putstr_fd("minishell: exit:", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": -n where n is a numeric", STDERR_FILENO);
		exit_code = 255;
	}
	free_arr(args);
	exit(exit_code);
}

int	custom_exit(t_sysvar *sys_var, char **args)
{
	if (args[1] && args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	free_sysvar(sys_var); //Not freed everything will come back for this later.
	exit_with_code(args);
	return (EXIT_SUCCESS);
}
