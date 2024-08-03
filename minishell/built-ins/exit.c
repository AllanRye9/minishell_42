/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:35:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 17:20:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_isnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	ft_skip_spaces_sign(char *arg, int *i, int *sign)
{
	while (arg[*i] && arg[*i] == ' ')
		(*i)++;
	if (arg[*i] == '+' || arg[*i] == '-')
	{
		if (arg[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

void	exit_with_code(char *args, t_minishell *g_shell)
{
	int					i;
	int					sign;
	int					exit_s;
	unsigned long long	result;

	i = 0;
	sign = 1;
	ft_skip_spaces_sign(args, &i, &sign);
	if (!ft_isnum(args + i))
	{
		ft_putstr_fd("minishell: exit:", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": -n where n is a numeric", STDERR_FILENO);
		ft_clean_ms(g_shell);
		exit(EXIT_FAILURE);
	}
	result = 0;
	while (args[i])
	{
		result = (result * 10) + (args[i] - '0');
		if (result > LONG_MAX)
		{
			ft_putstr_fd("minishell: exit:", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd(": -n where n is a numeric", STDERR_FILENO);
			ft_clean_ms(g_shell);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ((result * sign) % 256);
}

void	ft_exit(t_minishell *g_shell, char **args)
{
	int	exit_status;

	exit_status = g_shell->exit_s;
	if (args[1] && args[2] && ft_isnum(args[1]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		ft_clean_ms(g_shell);
		exit(exit_status);
	}
	else
		exit_status = ft_exit_with_code(args[1], g_shell);
	ft_clean_ms(g_shell);
	exit(exit_status);
}
