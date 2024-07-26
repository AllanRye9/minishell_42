#include "../include/minishell.h"

int handle_separators(char *l, t_token **t_lst)
{
    if (!strncmp(l, "<<", 2))
        return (append_list(INPUT_DELI, &l, t_lst), 1);
    else if (!strncmp(l, ">>", 2))
        return (append_list(OUTPUT_DELI, &l, t_lst), 1);
    else if (!strncmp(l, "&&", 2))
        return (append_list(AND, &l, t_lst), 1);
    else if (!strncmp(l, "||", 2))
        return (append_list(OR, &l, t_lst), 1);
    else if (!strncmp(l, "(", 1))
        return (append_list(O_PARENT, &l, t_lst), 1);
    else if (!strncmp(l, ")", 1))
        return (append_list(C_PARENT, &l, t_lst), 1);
    else if (!strncmp(l, "<", 1))
        return (append_list(INPUT_R, &l, t_lst), 1);
    else if (!strncmp(l, ">", 1))
        return (append_list(OUTPUT_R, &l, t_lst), 1);
    else
        return (append_list(PIPE, &l, t_lst), 1);
}

t_token *tokenization_handler(char *line, t_minishell *g_shell)
{
    int err;
    t_token *token_lst;

    err = 0;
    token_lst = NULL;
    while (*line) {
        if (err)
            return (clear_lst(&token_lst), NULL);
        if (is_space(*line))
            skip_space(&line);
        else if (!strncmp(line, "<", 1) || !strncmp(line, ">", 1) ||
                 !strncmp(line, "|", 1) || !strncmp(line, "&&", 2) ||
                 !strncmp(line, "(", 1) || !strncmp(line, ")", 1))
            err = (!handle_separators(line, &token_lst) && 1);
        else
            err = (!append_list(IDENDTIFIER, &line, &token_lst) && 1);
    }
    return token_lst;
}
