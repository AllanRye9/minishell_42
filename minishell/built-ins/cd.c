#include "../include/minishell.h"

void check_cd(char *path)
{
    if (ft_strcmp(path, "cd") == 0 && !path)
        return;
    else if (ft_strcmp(path, "cd") == 0 && path)
        chdir(path);
    else
        printf("Directory not found!");
}