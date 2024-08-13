/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:54:52 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 22:20:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_word_filler(const char *args, char **str, size_t *i, size_t j)
{
	char	quotes;
	size_t	k;

	k = 0;
	while (args[(*i)] && args[(*i)] != ' ')
	{
		if (args[(*i)] != '\'' && args[(*i)] != '"')
			str[j][k++] = args[(*i)++];
		else
		{
			quotes = args[(*i)++];
			str[j][k++] = quotes;
			while (args[(*i)] != quotes)
				str[j][k++] = args[(*i)++];
			str[j][k++] = args[(*i)++];
		}
	}
}

static char	**ft_filler(char const *args, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i] && str[j])
	{
		if (args[i] != ' ')
		{
			ft_word_filler(args, str, &i, j);
			j++;
		}
		while (args[i] && args[i] == ' ')
			i++;
	}
	return (str);
}

static void	ft_skip_word(char const *args, size_t *i)
{
	char	quotes;

	while (args[*i] && args[*i] != ' ')
	{
		if (args[*i] != '\'' && args[*i] != '"')
			(*i)++;
		else
		{
			quotes = args[(*i)++];
			while (args[(*i)] != quotes)
				(*i)++;
			(*i)++;
		}
	}
}

static char	**ft_allocator(char const *args, char **str)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i] != ' ')
		{
			start = i;
			ft_skip_word(args, &i);
			str[j] = ft_calloc(i - start + 1, sizeof(char));
			if (!str[j])
				return (NULL);
			j++;
		}
		while (args[i] && args[i] == ' ')
			i++;
	}
	return (str);
}

char	**split_doublearr(char const *args)
{
	size_t	count;
	char	**str;
	char	**free_str;
	size_t	i;

	if (!args)
		return (NULL);
	i = 0;
	count = 0;
	while (args[i])
	{
		if (args[i] != ' ' && ++count)
			ft_skip_word(args, &i);
		while (args[i] && args[i] == ' ')
			i++;
	}
	str = ft_calloc(count + 1, sizeof(char *));
	free_str = str;
	str = ft_allocator(args, str);
	if (!str || !count)
		return (free_doublearr(free_str), NULL);
	return (ft_filler(args, str));
}
