/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:12:49 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/22 17:19:59 by sbartoul         ###   ########.fr       */
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

void	free_doublearr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}

void	free_sysvar(t_sysvar *sys_var)
{
	free(sys_var->args);
	free_doublearr(sys_var->args);
	free_doublearr(sys_var->env);
	free_doublearr(sys_var->path);
	free(sys_var->pwd);
	free(sys_var->old_pwd); //Need to free everything pending here.
}

int	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	invalid_id(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+'
		|| c == '^' || c == '%' || c == '#' || c == '@' || c == '!'
		|| c == '~'
		|| c == '=' || c == '-' || c == '?' || c == '&' || c == '*')
		return (1);
	return (0);
}
