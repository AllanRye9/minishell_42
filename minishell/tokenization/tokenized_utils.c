#include "../include/minishell.h"

size_t ft_strcspn(char *start, char *delim)
{
    size_t i = 0;
    size_t j = 0;

    while(start[i])
    {
        j = 0;
        while(delim[j])
        {
            if (start[i] == delim[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

size_t ft_strchar(char *s, char c)
{
    size_t i = 0;

    while(s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

size_t ft_strspn(char *start, char *delim)
{
    size_t i = 0;

    while(start[i])
    {
        if (ft_strchar(delim, start[i]) == 0)
            break;
        i++;
    }
    return (i);
}