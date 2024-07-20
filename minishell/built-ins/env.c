/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/20 23:29:21 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	env(t_sysvar *sys_var)
{
	int	i;

	i = -1;
	while (sys_var->env[++i])
	{
		ft_putendl_fd(sys_var->env[i], STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
