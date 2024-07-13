#include "../include/minishell.h"

static int check_options(char *args)
{
    int i = 0;
    if (args[i] == '-')
        return (0);
    i++;
    while (args[i])
    {
        if (args[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

// Function to print an environment variable
static void print_env_var(char* var) {
    char* value = getenv(var);
    if (value) {
        ft_putstr_fd(value, 1);
    } else {
        ft_putstr_fd("", 1); // Print nothing if the variable is not set
    }
}

void ft_echo(char** args) {
    int i = 0;
    int opt = 0;

    // Check for -n option
    if (args[i] && check_options(args[i])) {
        opt = 1;
        i++;
    }

    // Print the arguments
    while (args[i]) {
        if (args[i][0] == '$') {
            print_env_var(&args[i][1]); // Print environment variable
        } else {
            ft_putstr_fd(args[i], 1);
        }

        if (args[i + 1]) // Print a space if there are more arguments
            ft_putstr_fd(" ", 1);
        
        i++;
    }

    // Print newline unless -n option was used
    if (!opt) {
        ft_putstr_fd("\n", 1);
    }
}