#include "../include/minishell.h"

int ft_strcmp(char *s, char *s1)
{
    int i = 0;
    while(s[i] && s1[i] && s1[i] == s[i])
        i++;
    return (s[i] - s1[i]);
}

