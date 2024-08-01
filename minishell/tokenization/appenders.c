/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appenders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:55:49 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 17:05:11 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_append_separators(t_token_type t, char **line, char **token_list)
{
    t_token *token;
    
    token = creat_new_token(NULL, t);
    if(!token)
        return (0);
    if (t == T_HEREDOC || t == T_APPEND || t == T_OR || t == T_AND)
		(*line)++;
    add_token_back(token_list, token);
        (*line)++;
    return (1);
}

int ft_append_identifiers(char **line, t_token **token_list, t_minishell *g)
{
    char    *arr;
    char    *value;
    t_token *token;
    size_t  i;
    
    arr = *line;
    i = 0;
    while(arr[i] && !ft_is_separator(arr + i))
    {
        if(ft_is_quote(arr[i]))
        {
            if(!ft_skip_quotes(arr, &i))
                return (ft_print_quotes_err(arr[i], g), NULL);
        }
        else
            i++;
    }
    value = ft_substr(arr, 0, i);
    if(!value)
        return (0);
    token = creat_new_token(value, IDENTIFIER);
    if(!token)
        return (free(value), 0);
    *line += i;
    return (add_token_back(token_list, token), 1);
}