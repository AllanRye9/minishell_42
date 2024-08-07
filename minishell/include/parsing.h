/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:48:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/07 12:15:14 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "tokenization.h"
#include "minishell.h"

typedef enum e_node_type
{
    N_PIPE,
    N_AND,
    N_OR,
    N_CMD
}   t_node_type;

typedef enum e_io_type
{
    IO_IN,
    IO_OUT,
    IO_HEREDOC,
    IO_APPEND
}   t_io_type;

typedef enum e_parse_err_type
{
    E_MEM = 1,
    E_SYNTAX
}   t_parse_err_type;

typedef struct s_io_node
{
    t_io_type        type;
    char            *value;
    char            **expanded_value;
    int             here_doc;
    struct s_io_node *prev;
    struct s_io_node *next;
}   t_io_node;

typedef struct s_node
{
    t_node_type      type;
    t_io_node        *io_list;
    char            *args;
    char            **expanded_args;
    struct s_node   *left;
    struct s_node   *right;
}   t_node;

typedef struct s_parse_err
{
    t_parse_err_type type;
    char            *str;
}   t_parse_err;

int                     ft_is_quote(char c);
int						ft_prec(t_token_type t);
int						ft_token_prec(t_minishell *g);
bool					ft_join_args(char **args, t_minishell *g);
bool					ft_get_io_list(t_io_node **io_l, t_minishell *g);
bool					ft_is_token_sep(t_minishell *g);
bool                    ft_is_redir(t_token_type t);
t_node					*ft_get_cmds(t_minishell *g);

t_node_type				ft_get_node_type(t_token_type t);
t_io_type				ft_get_io_type(t_token_type t);
t_io_node				*ft_new_io_node(t_token_type t, char *value);
t_node					*ft_define_grammar(t_minishell *g);

t_node					*ft_combine(t_token_type id, t_node* left, t_node *right, t_minishell *g);
t_node					*ft_expression(int i, t_minishell *g);
t_node					*ft_parse(t_minishell *g);
void					ft_get_next_token(t_minishell *g);
void					ft_append_io_node(t_io_node **lst, t_io_node *new);
void					ft_clear_io_list(t_io_node **lst);
void					ft_clear_cmd_node(t_node *node);
void					ft_recursive_clear_astree(t_node *node);
void					ft_clear_astree(t_node **astree, t_minishell *g);
void                    ft_clear_token_list(t_token **token_list);
void                    add_token_back(t_token **lst, t_token *new);
void					ft_handle_parse_err(t_minishell *g_minishell);
void					ft_set_parse_err(t_parse_err_type type, t_minishell *g_minishell);
t_node					*ft_new_node(t_node_type type);
char					**ft_globber(char **expanded);

#endif
