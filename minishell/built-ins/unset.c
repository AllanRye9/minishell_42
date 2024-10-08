/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:28:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:19:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_unset_helper(char *key, t_minishell *g_shell)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = g_shell->envlst;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				g_shell->envlst = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_minishell *g_shell, char **args)
{
	int		i;
	bool	error;

	i = 1;
	if (!args[1])
		return (0);
	error = false;
	while (args[i])
	{
		if (!ft_check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			error = true;
		}
		else
			ft_unset_helper(
				ft_garbage_collector(ft_extract_key(args[i]), false), g_shell);
		i++;
	}
	return (error);
}
