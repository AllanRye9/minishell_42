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
	int NoOfCmds = 2, i, flag = 0; 
	char* Handler[NoOfCmds]; 

	Handler[0] = "exit"; 
	Handler[1] = "cd";

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
	return 0; 
} 
