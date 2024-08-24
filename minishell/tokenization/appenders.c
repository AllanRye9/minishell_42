/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appenders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:55:49 by oallan            #+#    #+#             */
/*   Updated: 2024/08/24 12:19:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_spchar(char c)
{
	return (c == ';' || c == '\\');
}

int	ft_err_spchar(char c)
{
	ft_putstr_fd("minishell: invalid identifier ", 2);
	ft_putchar_fd('\'', 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	ft_append_separators(t_token_type t, char **line, t_token **token_list)
{
	t_token	*token;

	token = creat_new_token(NULL, t);
	if (!token)
		return (0);
	add_token_back(token_list, token);
	(*line)++;
	if (t == T_HEREDOC || t == T_APPEND || t == T_OR || t == T_AND)
		(*line)++;
	return (1);
}

int	ft_parse_identifier(char **line, size_t *i, t_minishell *g)
{
	char	*arr;

	arr = *line;
	while (arr[*i] && !ft_is_separator(arr + *i))
	{
		if (ft_is_spchar(arr[*i]))
			return (ft_err_spchar(arr[*i]));
		else if (ft_is_quote(arr[*i]))
		{
			if (!ft_skip_quotes(arr, i))
				return (ft_print_quotes_err(arr[*i], g), 0);
		}
		else
			(*i)++;
	}
	return (1);
}

int	ft_append_identifiers(char **line, t_token **token_list, t_minishell *g)
{
	char	*arr;
	char	*value;
	t_token	*token;
	size_t	i;

	arr = *line;
	i = 0;
	if (!ft_parse_identifier(line, &i, g))
		return (0);
	value = ft_substr(arr, 0, i);
	if (!value)
		return (0);
	token = creat_new_token(value, IDENTIFIER);
	if (!token)
		return (free(value), 0);
	*line += i;
	return (add_token_back(token_list, token), 1);
}
