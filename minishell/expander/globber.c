/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:51:51 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:24:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	ft_set_direntry(struct dirent **entry, DIR *dir)
{
	*entry = readdir(dir);
	return (true);
}

static bool	ft_matches_visibility(char *pattern, char *args)
{
	if ((pattern[0] == '.' && args[0] == '.')
		|| (pattern[0] != '.' && args[0] != '.'))
		return (true);
	return (false);
}

static char	**ft_globber_helper(char *args)
{
	char			**returned;
	DIR				*dir;
	struct dirent	*entry;
	size_t			match_count;

	match_count = ft_match_count(args);
	if (!ft_contains_asterisk(args) || !match_count)
	{
		returned = (char **)ft_calloc(2, sizeof(char *));
		returned[0] = ft_strdup(args);
		return (returned);
	}
	else
	{
		dir = opendir(".");
		returned = (char **)ft_calloc(match_count + 1, sizeof(char *));
		match_count = 0;
		while (ft_set_direntry(&entry, dir) && entry)
			if (ft_match_star(args, entry->d_name)
				&& ft_matches_visibility(args, entry->d_name))
				returned[match_count++] = ft_strdup(entry->d_name);
		closedir(dir);
	}
	return (returned);
}

char	**ft_globber(char **expanded)
{
	size_t	i;
	size_t	len;
	char	***globbed;

	len = ft_str_arr_len(expanded);
	globbed = (char ***)ft_calloc(len + 1, sizeof(char ***));
	i = 0;
	while (expanded[i])
	{
		globbed[i] = ft_globber_helper(expanded[i]);
		i++;
	}
	return (free_doublearr(expanded), ft_join_str_arrs(globbed));
}
