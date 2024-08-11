/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:28 by oallan            #+#    #+#             */
/*   Updated: 2024/08/11 22:44:43 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_clear_cmd_node(t_node *node)
{
    if(!node)
        return ;
    ft_clear_io_list(&(node->io_list));
    free(node->args);
    ft_free_char2(node->expanded_args);
}

void ft_recursive_clear_astree(t_node *node)
{
    if(!node)
        return ;
    if(node->type == N_CMD)
        ft_clear_cmd_node(node);
    else
    {
        if(node->left)
            ft_recursive_clear_astree(node->left);
        if(node->right)
            ft_recursive_clear_astree(node->right);
    }
    free(node);
}

void ft_clear_astree(t_node **astree, t_minishell *g)
{
    ft_recursive_clear_astree(*astree);
    *astree = NULL;
    ft_clear_token_list(&g->tokens);
}

void ft_clear_io_list(t_io_node **lst)
{
    t_io_node *c;
    t_io_node *next;
    
    c = *lst;
    if(!c)
        return ;
    while(c)
    {
        free(c->value);
        ft_free_char2(c->expanded_value);
        next = c->next;
        free(c);
        c = next;
    }
    *lst = NULL;
}
