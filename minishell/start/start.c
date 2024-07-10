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

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("This program does not accept arguments\n");
		return (0);
	}
	if (!ft_strcmp(argv[1], "pwd") || !ft_strcmp(argv[1], "PWD"))
		pwd_check(argv[1]);
	else if (!ft_strcmp(argv[1], "cd") || !ft_strcmp(argv[1], "CD"))
		check_cd(argv[1]);
	else
	{
		printf("Argument not found\n");
	}
}
