/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:06:53 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/03 23:54:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_handle_squotes(char *args, size_t *i)
{
	size_t	start;

	start = *i;
	(*i)++;
	while (args[*i] != '\'')
		(*i)++;
	(*i)++;
	return (ft_substr(args, start, *i - start));
}

static char	*ft_handle_dquote_args(char *args, size_t *i)
{
	size_t	start;

	start = *i;
	while (args[*i] != '"' && args[*i] != '$')
		(*i)++;
	return (ft_substr(args, start, *i - start));
}

char	*ft_handle_dquotes(char *args, size_t *i, t_minishell *g_shell)
{
	char	*tmp;

	tmp = ft_strdup("\"");
	(*i)++;
	while (args[*i] != '"')
	{
		if (args[*i] == '$')
			tmp = ft_strjoin_f(tmp, ft_handle_dollar(args, i, g_shell));
		else
			tmp = ft_strjoin_f(tmp, ft_handle_dquotes_args(args, i));
	}
	(*i)++;
	return (ft_strjoin_f(tmp, ft_strdup("\"")));
}

char	*ft_handle_arg(char *args, size_t *i)
{
	size_t	start;

	start = *i;
	while (args[*i] && args[*i] != '\'' && args[*i] != '"' && args[*i] != '$')
		(*i)++;
	return (ft_substr(args, start, *i - start));
}