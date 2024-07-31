/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:42:11 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/18 17:58:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# include "minishell.h"

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
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
int				ft_append_identifiers(char **line, t_token **token_list, t_minishell *g);
t_token			*ft_token_handler(char *line, t_minishell *g);
t_token			*ft_tokenize(t_minishell *g);
#endif
