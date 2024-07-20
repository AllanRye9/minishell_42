/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:45:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/20 15:54:55 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_path_to_env(t_sysvar *sys_var)
{
	int		i;
	char	*dir;

	i = -1;
	while (sys_var->env[++i])
	{
		if (!ft_strncmp(sys_var->env[i], "PWD=", 4))
		{
			dir = ft_strjoin("PWD=", sys_var->pwd);
			free(sys_var->env[i]);
			sys_var->env[i] = dir;
		}
		else if (!ft_strncmp(sys_var->env[i], "OLDPWD=", 7) && sys_var->old_pwd)
		{
			dir = ft_strjoin("OLDPWD=", sys_var->old_pwd);
			free(sys_var->env[i]);
			sys_var->env[i] = dir;
		}
	}
}