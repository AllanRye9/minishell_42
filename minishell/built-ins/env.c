/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:17:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_minishell *g_shell)
{
	t_env	*lst;

	lst = g_shell->envlst;
	while (lst)
	{
		if (lst->value != NULL)
			printf("%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
	return (ENO_SUCCESS);
}
