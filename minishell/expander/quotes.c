/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:01:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/04 01:11:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	ft_unquoted_len(char *args)
{
	size_t	i;
	size_t	len;
	char	quotes;

	i = 0;
	len = 0;
	while (args[i])
	{
		if (!quotes)
			quotes = args[i++];
		else if (args[i] == quotes)
			quotes = ((i++) && 0);
		else
			len += (i++ || 1);
	}
	return (len);
}

static void	ft_unquote_filler(char *args, size_t *i, char *ret_val, size_t *j)
{
	char	quotes;

	quotes = args[(*i)++];
	while (args[*i] != quotes)
		ret_val[(*i)++] = args[(*i)++];
	(*i)++;
}

char	*ft_rm_quotes(char *arg)
{
	char	*ret_val;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ret_val = ft_calloc(1 + ft_unquoted_len(arg), sizeof(char));
	if (!ret_val)
		return (NULL);
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
			ft_unquote_filler(arg, &i, ret_val, &j);
		else
			ret_val[j++] = arg[i++];
	}
	return (free(arg), ret_val);
}
