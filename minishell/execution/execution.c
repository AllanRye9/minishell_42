/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:57:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/05 02:58:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

// int	main(void)
// {
// 	char	*input;

// 	input = readline("Enter something: ");
// 	if (input && *input)
// 	{
// 		add_history(input);
// 	}
// 	printf("You entered: %s\n", input);
// 	free(input);
// }

// Function to execute builtin commands 
int CmdHandler(char** parsed) 
{ 
    int NoOfCmds = 3, i, flag = 0; 
    char* Handler[NoOfCmds]; 

    Handler[0] = "exit"; 
    Handler[1] = "cd";
    Handler[2] = "echo"; // Adding echo command

    i = 0;
    while(i < NoOfCmds)
    { 
        if (ft_strcmp(parsed[0], Handler[i]) == 0)
        { 
            flag = i + 1; 
            break; 
        }
        i++; 
    } 

    if (flag == 1)
        exit(0);
    else if (flag == 2)
    {
        chdir(parsed[1]);
        return 1;
    }
    else if (flag == 3)
    {
        // Handle echo command
        if (parsed[1] != NULL && ft_strcmp(parsed[1], "$PATH") == 0) {
            // Get the PATH environment variable
            char *path = getenv("PATH");
            if (path != NULL) {
                printf("%s\n", path);
            } else {
                printf("PATH variable is not set.\n");
            }
        } else {
            // Print the rest of the arguments to echo
            i = 1;
            int flag;
            while (parsed[i] != NULL) {
				if (parsed[i][0] =='-')
				{
                    i++;
                    flag = 1;
                }
                else if (parsed[i][0] == '$')
                {
                    i++;
                    flag = 1;
                }
				else
                {
                    printf("%s ", parsed[i]);
                    flag = 0;
                }
                i++;
            }
            if(!flag)
                printf("\n");
        }
        return 1;
    }
    return 0; 
} 