/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:17:46 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:17:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_options(char *args)
{
	int	i;

	i = 0;
	if (args[i] != '-')
		return (0);
	i++;
	while (args[i])
	{
		if (args[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	while (args[i] && check_options(args[i]) == 1)
	{
		opt = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!opt)
		ft_putstr_fd("\n", 1);
	return (0);
}
