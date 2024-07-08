/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/08 19:05:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_data	*data;

	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		return (0);
	}
	signal_handler();
	while (!SIG_QUIT && cmd != NULL)
	{
		line = readline(PROMPT_MSG);
		if (line == NULL || !ft_strcmp(line, "exit"))
			exit(0);
		if (lexer(line))
		{
			data = parser(line, envp);
			execution(data, envp);
		}
	}
	return (0);
}
