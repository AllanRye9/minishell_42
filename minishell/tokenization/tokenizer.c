#include "../include/minishell.h"

t_token *ft_tokenize(t_minishell *g)
{
    char    *line;
    t_token *token_list;
    
    line = g->line;
    token_list = ft_token_handler(line, g);
    free(line);
    g->line = NULL;
    return (token_list);
}
