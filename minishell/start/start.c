/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/23 13:20:43 by sbartoul         ###   ########.fr       */
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


int main(int argc, char **argv) 
{ 
	(void)argc;
	(void)argv;
	char inputString[MAXWORDS];
	char *parsedArgs[MAXCMD]; 
	char* parsedArgsPiped[MAXCMD];
	int execFlag = 0;

	ExitStatuses *turned;

	turned = (ExitStatuses *)malloc(sizeof(ExitStatuses) * MAXWORDS);
	if (!turned)
		free(turned);
	
    // infinite loop to take commands
	while (1) {
		// print shell line
		if (signal(SIGINT, sig_handler))
			ft_putstr_fd("\b", STDERR);
		else if (signal(SIGQUIT, sig_handler))
			ft_putstr_fd("\b", STDERR);
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
			execArgs(parsedArgs, turned);
		handleEcho(parsedArgs,turned);
		if (execFlag == 2) 
			execArgsPiped(parsedArgs, parsedArgsPiped); 
	} 
	return 0; 
} 
