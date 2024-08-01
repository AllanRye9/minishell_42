/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:44 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 15:56:45 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node *ft_parse(t_minishell *g)
{
    t_node *astree;
    
    g->curr_token = g->tokens;
    astree = ft_expression(0, g);
    if(!g->curr_token)
        return (ft_set_parse_err(E_SYNTAX, g), astree);
    return (astree);
}