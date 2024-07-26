#include "../include/minishell.h"

int append_list(t_token_type type, char **l, t_token **t_lst)
{
    t_token *token;

    token = create_new_token(NULL, type);
    if (!token)
        return 0;
    if (type == INPUT_DELI || type == OUTPUT_DELI ||
        type == OR || type == AND)
        (*l)++;
    token_add_back(t_lst, token);
    (*l)++;
    return 1;
}
