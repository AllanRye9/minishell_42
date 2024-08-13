/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:12:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:25 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_path	ft_get_envlst_path(char *path, char *cmd)
{
	size_t	i;
	t_err	err;
	char	*cmd_path;
	char	**split_path;

	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		cmd_path = ft_garbage_collector(ft_strjoin_with_f
				(ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
		err = ft_check_exec(cmd_path, true);
		if (err.no == ENO_SUCCESS)
			return ((t_path){(t_err){ENO_SUCCESS, 42, cmd_path}, cmd_path});
		i++;
	}
	free_doublearr(split_path);
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
}

t_path	ft_get_path(char *cmd, t_minishell *g_shell)
{
	char	*value;

	if (*cmd == '\0')
		return ((t_path){
			(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return ((t_path){ft_check_exec(cmd, false), cmd});
	value = ft_get_envlst_val("PATH", g_shell);
	if (value)
		return (ft_get_envlst_path(value, cmd));
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, cmd}, NULL});
}
