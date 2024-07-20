/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:13:24 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/20 15:13:27 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*find_path(t_sysvar *sysvar, char *path)
{
	int	i;

	while (sysvar->env[i])
	{
		if (!ft_strncmp(sysvar->env[i], path, ft_strlen(path)))
			return (ft_substr(sysvar->env[i], ft_strlen(path), ft_strlen(sysvar->env[i]) - ft_strlen(path)));
		i++;
	}
	return (NULL);
}
 
int	change_to(t_sysvar *sys_var, char *path)
{
	char	*dir;
	int		ret_value;

	dir = find_path(sys_var, path);
	ret_value = chdir(dir);
	free(dir);
	if (ret_value == -1)
	{
		path = ft_substr(path, 0, ft_strlen(path) - 1);
		ft_putstr_fd(path, STDERR_FILENO);
		free(path);
	}
	return (ret_value);
}

int	change_dir(t_sysvar *sysvar, char *path)
{
	int	ret_val;

	if (!path)
		ret_val = change_to(sysvar, "HOME=");
	else if (ft_strncmp(path, "-", 1) == 0)
		ret_val = change_to(sysvar, "OLDPWD=");
	else
	{
		ret_val = chdir(path);
		if (ret_val == -1)
		{
			ft_putstr_fd("Error:", STDERR_FILENO);
			ft_putstr_fd(path, STDERR_FILENO);
		}
	}
	if (ret_val == -1)
		return (EXIT_FAILURE);
	change_path(sysvar);
	add_path_to_env(sysvar);
	return (EXIT_SUCCESS);
}
