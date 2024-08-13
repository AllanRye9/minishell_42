/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_emptyquotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:29:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/13 15:24:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*handle_empty_quotes(char *args)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;
	size_t	dstsize;

	if ((args[0] == '\'' && args[1] == '\'' && !args[2])
		|| (args[0] == '"' && args[1] == '"' && !args[2]))
		return (args);
	tmp = ft_calloc(ft_strlen(args) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (args[i])
	{
		if ((args[i] == '\'' && args[i + 1] == '\'')
			|| (args[0] == '"' && args[i + 1] == '"'))
			i += 2;
		else
			tmp[j++] = args[i++];
	}
	free(args);
	dstsize = ft_strlen(tmp) + 1;
	ret = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(ret, tmp, dstsize), free(tmp), ret);
}

bool	ft_is_valid_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}
