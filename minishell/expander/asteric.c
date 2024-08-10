/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:16:20 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/10 22:59:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	match_exist(char **pattern, char **last_wildcard, char **last_match, char **args)
{
	if (**pattern == **args)
	{
		(*pattern)++;
		(*args)++;
		return (true);
	}
	else if (*last_wildcard)
	{
		*args = ++(*last_match);
		*pattern = *last_wildcard;
		return (true);
	}
	else
		return (false);
}

static bool	ft_handle_stars(char **pattern, char **last_wildcard, char **last_match, char *args)
{
	while (**pattern == '*')
		(*pattern)++;
	if (!**pattern)
		return (true);
	*last_wildcard = *pattern;
	*last_match = args;
	return (false);
}

static void	handle_quotes(char **pattern, char *quotes)
{
	if (**pattern == '"' || **pattern == '\'')
	{
		if (!*quotes)
			*quotes = *(*pattern)++;
		else
		{
			if (*quotes == **pattern)
			{
				*quotes = 0;
				(*pattern)++;
			}
		}
	}
}

bool	ft_match_star(char *pattern, char *args)
{
	char	*last_wildcard;
	char	*last_match;
	char	quotes;

	quotes = 0;
	last_wildcard = NULL;
	last_match = NULL;
	while (*args)
	{
		handle_quotes(&pattern, &quotes);
		if (*pattern == '*' && !quotes
				&& ft_handle_stars(&pattern, &last_wildcard, &last_match, args))
			return (false);
		else if (!match_exist(&pattern, &last_wildcard, &last_match, &args))
			return (false);
	}
	if (*pattern == '*')
		while (*pattern == '*')
			pattern++;
	return (!*pattern);
}
