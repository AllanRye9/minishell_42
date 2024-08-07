/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:41 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 12:14:56 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_io_type   ft_get_io_type(t_token_type t)
{
    if(t == T_R_INPUT)
        return (IO_IN);
    if(t == T_R_OUT)
        return (IO_OUT);
    if(t == T_HEREDOC)
        return (IO_HEREDOC);
    return (IO_APPEND);
}

t_io_node *ft_new_io_node(t_token_type t, char *value)
{
    t_io_node *new;
    
    new = (t_io_node *)ft_calloc(1, sizeof(t_io_node));
    if(!new)
        return NULL;
    new->type = ft_get_io_type(t);
    new->value = ft_strdup(value);
    if(!new->value)
        return (free(new), NULL);
    return (new);
}

void    ft_append_io_node(t_io_node **lst, t_io_node *new)
{
    t_io_node *c;
    
    if(!*lst)
    {
        *lst = new;
        return ;
    }
    c = *lst;
    while(c && c->next)
        c = c->next;
    c->next = new;
}

t_node_type ft_get_node_type(t_token_type t)
{
    if(t == T_AND)
        return (N_AND);
    if(t == T_OR)
        return (N_OR);
    return (N_PIPE);
}

bool    ft_get_io_list(t_io_node **io_list, t_minishell *g)
{
    t_token_type    redir_t;
    t_io_node       *tem;
    
    if(g->parse_err.type)
        return (false);
    while(g->curr_token && ft_is_redir(g->curr_token->type))
    {
        redir_t = g->curr_token->type;
        ft_get_next_token(g);
        if(!g->curr_token)
            return (ft_set_parse_err(E_SYNTAX, g), false);
        if (g->curr_token->type != IDENTIFIER)
            return (ft_set_parse_err(E_SYNTAX, g), false);
        tem = ft_new_io_node(redir_t, g->curr_token->value);
        if(!tem)
            return (ft_set_parse_err(E_MEM, g), false);
        ft_append_io_node(io_list, tem);
        ft_get_next_token(g);
    }
    return (true);
}