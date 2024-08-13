/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:35:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 10:41:14 by sbartoul         ###   ########.fr       */
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

int	exit_with_code(char *args, t_minishell *g_shell)
{
	int					i;
	int					sign;
	int					exit_status;
	unsigned long long	result;

	i = 0;
	sign = 1;
	ft_skip_spaces_sign(args, &i, &sign);
	if (!ft_isnum(args + i))
	{
		exit_status = ft_err_msg((t_err){ENO_EXEC_255, ERRMSG_NUMERIC_REQUI, args});
		ft_clean(g_shell);
		exit(exit_status);
	}
	result = 0;
	while (args[i])
	{
		result = (result * 10) + (args[i] - '0');
		if (result > LONG_MAX)
		{
			exit_status = ft_err_msg((t_err){ENO_EXEC_255, ERRMSG_NUMERIC_REQUI, args});
			(ft_clean(g_shell), exit(exit_status));
		}
		i++;
	}
	return ((result * sign) % 256);
}

void	ft_exit(t_minishell *g_shell, char **args)
{
	int	exit_status;

	exit_status = g_shell->exit_s;
	if (args[1])
	{
		if (args[2] && ft_isnum(args[1]))
		{
			exit_status = ft_err_msg((t_err){ENO_GENERAL, ERRMSG_TOO_MANY_ARGS, NULL});
			ft_clean(g_shell);
			exit(exit_status);
		}
		else
			exit_status = exit_with_code(args[1], g_shell);
	}
	ft_clean(g_shell);
	exit(exit_status);
}
