/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:16 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 15:56:17 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *ft_tokenize(t_minishell *g)
{
    char    *line;
    t_token *token_list;
    
    line = g->line;
    token_list = ft_token_handler(line, g);
    free(line);
    g->line = NULL;
    return (token_list);
}
