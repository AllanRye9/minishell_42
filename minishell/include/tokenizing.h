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
# define PROMPT_MSG "minishell-$ "

typedef enum token_type
{
	IDENDTIFIER,
	INPUT_R,
	OUTPUT_R,
	INPUT_DELI,
	OUTPUT_DELI,
	PIPE,
	O_PARENT,
	C_PARENT,
	AND,
	OR,
	NL
}	t_token_type;

typedef struct token
{
	t_token_type		token_t;
	char				*value;
	struct token		*next;
	struct token		*prev;
}	t_token;

//functions here ----->
t_token				*ft_tokenize(t_minishell *g_shell);
void				clear_lst(t_token **lst);
int					is_space(char c);
void				skip_space(char **l);
t_token				*create_new_token(char *value, t_token_type type);
void				token_add_back(t_token **lst, t_token *new);
int					append_list(t_token_type type, char **l, t_token **t_lst);
int					handle_separators(char *l, t_token **t_lst);
t_token				*tokenization_handler(char *line, t_minishell *g_shell);
#endif
