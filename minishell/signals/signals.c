#include "../include/minishell.h"

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
            return (c + 32);
    return c;
}

static int get_digit(char c, int base)
{
    int max;
    if (base <= 10)
        max = c + '0';
    else 
        max = base - 10 + 'a';
    if (c >= '0' && c <= '9' && c <= max)
        return (c - '0');
    else if (c >= 'a' && c <= 'f' && c <= max)
        return (c + 10 - 'a');
    else
        return -1;
}

int ft_atoi_base(char *s, int base)
{
    int sign = 1;
    int res = 0;
    int digit;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    while((digit = get_digit(to_lower(*s), base)) > 0)
    {
        res = (res * base);
        res = (res * sign) + digit;
        s++;
    }
    return res;
}
