/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:31 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 17:03:41 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_set_parse_err(t_parse_err_type type, t_minishell *g_minishell)
{
	g_minishell->parse_err.type = type;
}

void	ft_handle_parse_err(t_minishell *g_minishell)
{
	t_parse_err_type	type;
	t_token_type		token_type;
	char				**types;

	types = (char *[]){"IDENTIFIER",
		"<", ">", "<<", ">>", "|", "(", ")", "&&", "||", "newline"};
	type = g_minishell->parse_err.type;
	(void)token_type;
	(void)types;
	if (type)
	{
		if (type == E_SYNTAX)
		{
			if (!g_minishell->curr_token)
				token_type = T_NL;
			else
				token_type = g_minishell->curr_token->type;
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
			g_minishell->exit_s = 258;
		}
		ft_clear_ast(&g_minishell->ast, g_minishell);
		ft_bzero(&g_minishell->parse_err, sizeof(t_parse_err));
	}
}