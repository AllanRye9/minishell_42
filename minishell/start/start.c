/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/10 19:05:44 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	main(int argc, char *argv[], char *envp[])
// {
	// char	*line;
	// t_data	*data;

	// if (argc != 1)
	// {
	// 	printf("This program does not accept arguments\n");
	// 	return (0);
	// }
	// char *s;
	// if (argc == 1)
	// 	printf("%s\n", getcwd(s, 100));
	// else
	// {
	// 	if (ft_strcmp(argv[1], "cd") && argv[2])
	// 		chdir(argv[2]);
	// 	else
	// 		printf("Directory not found!");
	// }
	// signal_handler();
	// while (!SIG_QUIT && cmd != NULL)
	// {
	// 	line = readline(PROMPT_MSG);
	// 	if (line == NULL || !ft_strcmp(line, "exit"))
	// 		exit(0);
	// 	if (lexer(line))
	// 	{
	// 		data = parser(line, envp);
	// 		execution(data, envp);
	// 	}
	// }
// 	return (0);
// }


int main() 
{ 
	char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
	char* parsedArgsPiped[MAXLIST]; 
	int execFlag = 0; 

	while (1) { 
		// print shell line 
		printDir(); 
		// take input 
		if (takeInput(inputString)) 
			continue; 
		// process 
		execFlag = processString(inputString, parsedArgs, parsedArgsPiped); 
		// execflag returns zero if there is no command 
		// or it is a builtin command, 
		// 1 if it is a simple command 
		// 2 if it is including a pipe. 

		// execute 
		if (execFlag == 1) 
			execArgs(parsedArgs); 

		if (execFlag == 2) 
			execArgsPiped(parsedArgs, parsedArgsPiped); 
	} 
	return 0; 
} 
