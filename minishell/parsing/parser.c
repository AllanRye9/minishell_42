/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:44 by oallan            #+#    #+#             */
/*   Updated: 2024/08/13 14:07:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*ft_parse(t_minishell *g)
{
	t_node	*astree;

	g->curr_token = g->tokens;
	astree = ft_expression(0, g);
	if (g->curr_token)
		return (ft_set_parse_err(E_SYNTAX, g), astree);
	return (astree);
}

int	ft_token_prec(t_minishell *g)
{
	return (ft_prec(g->curr_token->type));
}
