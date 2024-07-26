#include "../include/minishell.h"

void clear_lst(t_token **lst)
{
    t_token *c;
    t_token *n;

    c = *lst;
    if (!c)
        return;
    while (c) {
        free(c->value);
        n = c->next;
        free(c);
        c = n;
    }
    *lst = NULL;
}

int is_space(char c) {
    if (c == '\t' || c == '\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return 1;
    return 0;
}

void skip_space(char **l) {
    while (**l && is_space(**l))
        (*l)++;
}