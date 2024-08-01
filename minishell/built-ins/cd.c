/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:13:24 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 16:20:18 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	return_homedir(t_minishell *g_shell)
{
	char	*home;

	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD", g_shell), false, g_shell);
	home = ft_get_envlst_val("HOME", g_shell);
	if (!home)
		return (ft_putstr_fd("minishell: cd: Home not set\n", 2), 1);
	if (chdir(home) == 0)
		return (ft_update_envlst("PWD", home, false, g_shell), 0);
	return (1);
}

static int	ft_chdir(t_minishell *g_shell)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (1);
	return (ft_update_envlst("PWD", current_dir, false, g_shell), 0);
}

int	ft_cd(t_minishell *g_shell, char *path)
{
	int	ret_val;

	if (!path)
		return (return_homedir(g_shell));
	if (chdir(path) == -1)
		return (ft_cd_err(path));
	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD", g_shell), false, g_shell);
	return (ft_chdir(g_shell));
}
