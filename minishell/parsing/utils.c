/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:48 by oallan            #+#    #+#             */
/*   Updated: 2024/08/13 14:07:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_next_token(t_minishell *g)
{
	g->curr_token = g->curr_token->next;
}

bool	ft_is_redir(t_token_type t)
{
	if (t == T_R_INPUT || t == T_R_OUT || t == T_HEREDOC
		|| t == T_APPEND)
		return (true);
	return (false);
}

bool	ft_join_args(char **args, t_minishell *g)
{
	char	*to_free;

	if (g->parse_err.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (g->curr_token && g->curr_token->type == IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, g->curr_token->value, ' ');
		if (!*args)
			return (free(to_free), false);
		free(to_free);
		ft_get_next_token(g);
	}
	return (true);
}

bool	ft_is_token_sep(t_minishell *g)
{
	t_token_type	t;

	if (!g->curr_token)
		return (NULL);
	t = g->curr_token->type;
	if (t == T_AND || t == T_OR || t == T_PIPE)
		return (true);
	return (false);
}

int	ft_prec(t_token_type t)
{
	if (t == T_OR || t == T_AND)
		return (0);
	return (1);
}
