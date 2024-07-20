/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:12:49 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/20 15:40:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	change_path(t_sysvar *sys_var)
{
	char	*dir;

	dir = ft_strdup(sys_var->pwd);
	free(sys_var->old_pwd);
	sys_var->old_pwd = dir;
	free(sys_var->pwd);
	sys_var->pwd = getcwd(NULL, sizeof(NULL));
}
