/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:43:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/15 18:20:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_handle_dollar(char *args, size_t *i, t_minishell *g_shell)
{
	size_t	start;
	char	*var;
	char	*env_val;

	(*i)++;
	if (ft_isdigit(args[*i]) || args[*i] == '@')
	{
		(*i)++;
		return (ft_strdup(""));
	}
	else if (args[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(g_shell->exit_s));
	}
	else if (!ft_is_valid_char(args[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (ft_is_valid_char(args[*i]))
		(*i)++;
	var = ft_substr(args, start, *i - start);
	env_val = ft_get_envlst_val(var, g_shell);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

static char	*ft_handle_wildcard(char *args, t_minishell *g_shell)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strdup("");
	i = 0;
	while (args[i])
	{
		if (args[i] == '\'')
			tmp = ft_strjoin_f(tmp, ft_handle_squotes(args, &i));
		else if (args[i] == '"')
			tmp = ft_strjoin_f(tmp, ft_handle_dquotes(args, &i, g_shell));
		else if (args[i] == '$')
			tmp = ft_strjoin_f(tmp, ft_handle_dollar(args, &i, g_shell));
		else
			tmp = ft_strjoin_f(tmp, ft_handle_arg(args, &i));
	}
	return (tmp);
}

char	**ft_expand(char *args, t_minishell *g_shell)
{
	char	**expanded_args;
	char	**globbed_args;
	size_t	i;

	args = ft_handle_wildcard(args, g_shell);
	if (!args)
		return (NULL);
	args = handle_empty_quotes(args);
	if (!args)
		return (NULL);
	expanded_args = split_doublearr(args);
	free(args);
	if (!expanded_args)
		return (NULL);
	globbed_args = ft_globber(expanded_args);
	if (!globbed_args)
		return (NULL);
	i = 0;
	while (globbed_args[i])
	{
		globbed_args[i] = ft_rm_quotes(globbed_args[i]);
		i++;
	}
	return (globbed_args);
}
