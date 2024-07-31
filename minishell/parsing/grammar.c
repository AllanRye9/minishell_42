#include "../include/minishell.h"

t_node *ft_get_cmds(t_minishell *g)
{
    t_node *node;
    
    if(g->parse_err.type)
        return (NULL);
    node = creat_new_token(N_CMD);
    if(!node)
        return (ft_set_parse_err(E_MEM, g), NULL);
    while(g->curr_token && (g->curr_token->type == T_IDENTIFIER
    || ft_is_redir(g->curr_token->type)))
    {
        if(g->curr_token->type == T_IDENTIFIER)
        {
            if(!ft_join_args(&(node->args), g))
                return (ft_clear_cmd_node(node), ft_set_parse_err(E_MEM, g), NULL);
        }
        else if (ft_is_redir(g->curr_token->type))
        {
            if(!ft_get_io_list(&(node->io_list), g))
                return (free(node->args), free(node), NULL);
        }
    }
    return (node);
}

t_node *ft_define_grammar(t_minishell *g)
{
    t_node *node;
    
    if(g->parse_err.type)
        return(NULL);
    if(ft_is_token_sep(g) || g->curr_token->type == T_C_PARENT)
        return (ft_set_parse_err(E_SYNTAX, g), NULL);
    else if (g->curr_token->type == T_O_PARENT)
    {
        ft_get_next_token(g);
        node = ft_expression(0, g);
        if(!node)
            return (ft_set_parse_err(E_MEM, g), NULL);
        if(!g->curr_token || g->curr_token->type != T_C_PARENT)
            return (ft_set_parse_err(E_SYNTAX, g), node);
        ft_get_next_token(g);
        return (node);
    }
    else
        return (ft_get_cmds(g));
}