/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:28:43 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/03 16:20:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_writer(char *args, size_t i, int fd, t_minishell *g_shell)
{
	size_t	start;
	char	*tmp;

	start = ++i;
	if (args[i] == '?')
		return (ft_putnbr_fd(g_shell->exit_s, fd), 2);
	while (args[i] && args[i] != '$' && args[i] != ' ')
		i++;
	if (i != start)
	{
		tmp = ft_garbage_collector(ft_substr(args, start, i), false);
		tmp = ft_get_envlst_val(tmp, g_shell);
		if (tmp)
			ft_putstr_fd(tmp, fd);
	}
	return (i);
}

void	ft_heredoc_expander(char *args, int fd, t_minishell *g_shell)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '$')
			i += ft_writer(args, i, fd, g_shell);
		else
		{
			ft_putchar_fd(args[i], fd);
			i += 1;
		}
	}
	ft_putchar_fd('\n', fd);
}
