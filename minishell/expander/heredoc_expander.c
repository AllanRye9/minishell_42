/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:28:43 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/01 18:37:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



void	ft_heredoc_expander(char *args, int fd, t_minishell *g_shell)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '$')
			i += ft_write(args, i, fd, g_shell);
		else
		{
			ft_putchar_fd(args[i], fd);
			i += 1;
		}
	}
	ft_putchar_fd('\n', fd);
}
