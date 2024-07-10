#include "../include/minishell.h"

void pwd_check(char *path)
{
    char *str;

    str = getcwd(path, 100);
    printf("%s\n", str);
}