/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globber_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:41:37 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/10 23:01:16 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	ft_contains_asterisk(char *args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '*')
			return (true);
		i++;
	}
	return (false);
}

size_t	ft_match_count(char *pattern)
{
	DIR				*dir;
	size_t			match_cnt;
	struct dirent	*entry;

	match_cnt = 0;
	dir = opendir(".");
	entry = readdir(dir);
	while (entry)
	{
		if (ft_match_star(pattern, entry->d_name))
			match_cnt++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (match_cnt);
}

size_t	ft_str_arr_len(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static size_t	ft_multi_arr_len(char ***arr)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		len += 1;
		i++;
	}
	return (len);
}

char	**ft_join_str_arrs(char ***arr)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**joined;

	len = ft_multi_arr_len(arr);
	joined = (char **)ft_calloc(len + 1, sizeof(char *));
	i = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			joined[len + j] = ft_strdup(arr[i][j]);
			j++;
		}
		len += 1;
		i++;
	}
	return (free_tripearr(arr), joined);
}
