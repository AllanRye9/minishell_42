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
int ownCmdHandler(char** parsed) 
{ 
	int NoOfOwnCmds = 4, i, switchOwnArg = 0; 
	char* ListOfOwnCmds[NoOfOwnCmds]; 
	char* username; 

	ListOfOwnCmds[0] = "exit"; 
	ListOfOwnCmds[1] = "cd"; 
	ListOfOwnCmds[2] = "help"; 
	ListOfOwnCmds[3] = "hello"; 

	for (i = 0; i < NoOfOwnCmds; i++) { 
		if (ft_strcmp(parsed[0], ListOfOwnCmds[i]) == 0) { 
			switchOwnArg = i + 1; 
			break; 
		} 
	} 

	switch (switchOwnArg) { 
	case 1: 
		exit(0); 
	case 2: 
		chdir(parsed[1]); 
		return 1;
	case 4: 
		username = getenv("USER"); 
		printf("%s\n", username); 
		return 1; 
	default: 
		break; 
	} 

	return 0; 
} 

