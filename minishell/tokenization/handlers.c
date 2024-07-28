#include "../include/minishell.h"

int handle_separators(char *l, t_token **token)
{
    if (!strncmp(l, "<<", 2))
        return (append_list(INPUT_DELI, &l, token), 1);
    else if (!strncmp(l, ">>", 2))
        return (append_list(OUTPUT_DELI, &l, token), 1);
    else if (!strncmp(l, "&&", 2))
        return (append_list(AND, &l, token), 1);
    else if (!strncmp(l, "||", 2))
        return (append_list(OR, &l, token), 1);
    else if (!strncmp(l, "(", 1))
        return (append_list(O_PARENT, &l, token), 1);
    else if (!strncmp(l, ")", 1))
        return (append_list(C_PARENT, &l, token), 1);
    else if (!strncmp(l, "<", 1))
        return (append_list(INPUT_R, &l, token), 1);
    else if (!strncmp(l, ">", 1))
        return (append_list(OUTPUT_R, &l, token), 1);
    else
        return (append_list(PIPE, &l, token), 1);
}

t_token *tokenization_handler(char *line, t_minishell *g_shell)
{
    int err;
    t_token *token;

    err = 0;
    token = NULL;
    while (*line) {
        if (err)
            return (clear_lst(&token), NULL);
        if (is_space(*line))
            skip_space(&line);
        else if (!strncmp(line, "<", 1) || !strncmp(line, ">", 1) ||
                 !strncmp(line, "|", 1) || !strncmp(line, "&&", 2) ||
                 !strncmp(line, "(", 1) || !strncmp(line, ")", 1))
            err = (!handle_separators(line, &token) && 1);
        else
            err = (!append_list(IDENDTIFIER, &line, &token) && 1);
    }
    return token;
}
