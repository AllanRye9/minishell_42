#include "../include/minishell.h"

t_token *ft_tokenize(t_minishell *g_shell)
{
    char *line;
    t_token *token_list;

    line = g_shell->line;
    token_list = tokenization_handler(line, g_shell);
    free(line);
    g_shell->line = NULL;
    return token_list;
}
