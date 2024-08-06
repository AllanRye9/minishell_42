/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:19 by oallan            #+#    #+#             */
/*   Updated: 2024/08/06 18:27:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
t_node	*ft_new_node(t_node_type type)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	return (new_node);
}

t_token	*creat_new_token(char *value, t_token_type type)
{
	t_token	*new_token;

	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	return (new_token);
=======
t_node *creat_new_token(t_token_type type)
{
    t_node *new;
    
    new = (t_node *)ft_calloc(1, sizeof(t_node));
    if(!new)
        return NULL;
    new->type = type;
    return (new);
>>>>>>> 819205a (fixing compilation error)
}

void add_token_back(t_token **lst, t_token *new)
{
    t_token *c;
    
    if(!*lst)
    {
        *lst = new;
        return ;
    }
    c = *lst;
    while(c && c->next)
        c = c->next;
    c->next = new;
    c->prev = c;
}

bool    ft_skip_quotes(char *line, size_t *i)
{
    char q;
    
    q = line[*i];
    if(ft_strchr(line + *i + 1, q))
    {
        (*i)++;
        while(line[*i] != q)
            (*i)++;
        (*i)++;
        return (true);
    }
    return (false);
}

int ft_is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\f' || c == '\n' ||
        c == '\r')
        return (1);
    return (0);
}

void ft_skip_spaces(char **line)
{
    while(**line && ft_is_space(**line))
        (*line)++;
}

int ft_is_separator(char *s)
{
    if (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t'
		|| *s == '<' || *s == '>' || *s == '|' || *s == '(' || *s == ')')
		return (1);
	return (0);
}

int ft_is_quote(char c)
{
    if (c == '\'' || c == '"')
        return (1);
    return (0);
}