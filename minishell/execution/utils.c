/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:27:51 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/04 13:19:04 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_delimeter(char *deli, char *arg)
{
	while (*arg)
	{
		if (*deli == '"' || *deli == '\'')
		{
			deli++;
			continue ;
		}
		else if (*arg == *deli)
		{
			arg++;
			deli++;
		}
		else
			return (false);
	}
	while (*deli == '"' || *deli == '\'')
		deli++;
	return (!*deli);
}

static void	ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*ft_garbage_collector(void *ptr, bool clean)
{
	static t_list	*garbage_list;

	if (clean)
	{
		ft_lstclear(&garbage_list, ft_del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}
