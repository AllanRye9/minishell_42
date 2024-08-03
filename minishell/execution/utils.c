/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:27:51 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/01 17:41:52 by sbartoul         ###   ########.fr       */
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
