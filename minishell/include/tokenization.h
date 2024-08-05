/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:42:11 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 17:07:50 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# define PROMPT "minishell$ "

#include "minishell.h"

typedef enum e_token_type
{
	IDENTIFIER,
	T_R_INPUT,
	T_R_OUT,
	T_HEREDOC,
	T_APPEND,
	T_PIPE,
	T_O_PARENT,
	T_C_PARENT,
	T_AND,
	T_OR,
	T_NL,
}	t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;


//functions here ----->
bool			ft_skip_quotes(char *line, size_t *l);
void			ft_print_quotes_err(char c, t_minishell *g);
void			ft_skip_spaces(char **line);
int				ft_is_space(char c);
int				ft_is_separator(char *s);
int				ft_is_quote(char c);
int 			ft_append_separators(t_token_type t, char **line, t_token **token_list);
int				ft_append_identifiers(char **line, t_token **token_list, t_minishell *g);
t_token			*ft_token_handler(char *line, t_minishell *g);
t_token			*ft_tokenize(t_minishell *g);
t_token			*creat_new_token(char *value, t_token_type type);
#endif
