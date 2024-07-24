/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:24:06 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/22 19:53:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	after_eql_sign(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			return (i + 1);
	return (0);
}

char	*delete_quotes(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			ft_strlcpy(&str[i], &str[i + j], strlen(str) - i);
		}
		i++;
	}
	return (str);
}

char	**add_in_env(char **env, char **strings, char *argv)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
	{
		strings[i] = ft_strdup(env[i]);
		i++;
	}
	strings[i] = ft_strdup(argv);
	strings[i + 1] = NULL;
	return (strings);
}

char	**add_var(char **env, char *argv)
{
	char	**strings;
	int		i;

	i = 0;
	while (argv[after_eql_sign(argv)] == '\"' && i < 2)
	{
		delete_quotes(argv, '\"');
		i++;
	}
	i = 0;
	while (env[i] != NULL)
		i++;
	strings = ft_calloc(sizeof(char *), i + 2);
	if (!strings)
		return (NULL);
	i = 0;
	add_in_env(env, strings, argv);
	return (strings);
}
