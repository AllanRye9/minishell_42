/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:55:54 by oallan            #+#    #+#             */
/*   Updated: 2024/08/13 14:21:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token_list(t_token **token_list)
{
	t_token	*c;
	t_token	*next;

	c = *token_list;
	if (!c)
		return ;
	while (c)
	{
		free(c->value);
		next = c->next;
		free(c);
		c = next;
	}
	*token_list = NULL;
}

void	ft_print_quotes_err(char c, t_minishell *g)
{
	ft_putstr_fd("minishell: unexpected EOF While looking for ->", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\n", 2);
	g->exit_s = 258;
}
