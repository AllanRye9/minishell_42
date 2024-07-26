#include "../include/minishell.h"

t_token *create_new_token(char *value, t_token_type type)
{
    t_token *new;

    new = (t_token *)calloc(1, sizeof(t_token));
    if (!new)
        return NULL;
    new->value = value;
    new->token_t = type;
    return new;
}

void token_add_back(t_token **lst, t_token *new)
{
    t_token *c;

    if (!*lst)
	{
        *lst = new;
        return;
    }
    c = *lst;
    while (c && c->next)
        c = c->next;
    c->next = new;
    new->prev = c;
}