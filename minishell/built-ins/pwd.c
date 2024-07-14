#include "../include/minishell.h"

void pwd_check(char *path)
{
    char *str;

    str = getcwd(path, ft_strlen(path));
    printf("%s\n", str);
}