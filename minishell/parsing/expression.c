#include "../include/minishell.h"

t_node *ft_combine(t_token_type id, t_node* left, t_node *right, t_minishell *g)
{
    t_node *node;
    
    if(g->parse_err.type)
        return (NULL);
    node = creat_new_token(ft_get_node_type(id));
    if(!node)
        return(ft_set_parse_err(E_MEM, g), NULL);
    node ->left = left;
    node ->right = right;
    return (node);
}

t_node *ft_expression(int i, t_minishell *g)
{
   t_node           *left;
   t_node           *right;
   int              j;
   t_token_type     id;
   
    if (g->parse_err.type || !g->curr_token)
        return NULL;
    left = ft_define_grammar(g);
    if(!left)
        return (NULL);
    while(ft_is_token_sep(g) && ft_token_prec(g) >= i)
    {
        id = g->curr_token->type;
        ft_get_next_token(g);
        if(!g->curr_token)
            return(ft_set_parse_err(E_SYNTAX, g), left);
        j = ft_prec(id) + 1;
        right = ft_expression(j, g);
        if(!right)
            return(left);
        left = ft_combine(id, left, right, g);
        if(!left)
            return (ft_clear_astree(&left, g), ft_clear_astree(&right, g), NULL);
    }
    return (left);
}