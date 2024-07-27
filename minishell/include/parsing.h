/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:48:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/20 15:38:40 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef enum	parsing_error_type
{
	MEM_ERROR = 1,
	SYNTAX_ERROR
}	t_pars_err_type;

typedef struct	parsing_err
{
	t_pars_err_type	error_type;
	char			*str;
}	t_parse_error;

typedef enum	node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_COMMANDS
}	t_node_type;

typedef struct	env
{
	char		*key;
	char		*value;
	struct env	*next;
}	t_env;

typedef enum	io_types
{
	IN,
	OUT,
	HEREDOC,
	APPEND
}	t_io_type;

typedef struct s_io_node
{
    t_io_type        type;
    char            *value;
    char            **expanded_value;
    int             here_doc;
    struct s_io_node *prev;
    struct s_io_node *next;
}   t_io_node;
//Added the t_io_node -------->

typedef struct node
{
	t_node_type		node_type;
	t_io_type		*io_type;
	t_io_node       *io_list;
	char			*arg;
	char			*expanded_args;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct sys_variable
{
	char				*args;
	t_token				*tokens;
	t_token				*current_token;
	t_node				*node;
	int					exit_status;
	int					sigint_child;
	t_parse_error		parsing_error;
	int					stdin;
	int					stdout;
	char				**env;
	char				**path;
	t_env				*env;
	char				*pwd; //need to initialize during parsing.
	char				*old_pwd;
	bool				heredoc_sigint;
}	t_sysvar;

int						ft_prec(t_token_type type);
int						ft_curr_token_prec(t_minishell *ptr);
t_node					*ft_term(t_minishell *passed);
t_node					*ft_get_cmd(t_minishell *cmds);
t_node					*ft_expression(int min_prec, t_minishell *passed);
t_node					*ft_merge(t_token_type op, t_node *left, t_node *right);
t_node					*ft_parse(t_minishell *G_shell_);
t_node_type				get_node_type(t_token_type type);
t_io_type				ft_get_io_type(t_token_type type);
t_io_node				*ft_new_io_node(t_token_type type, char *value);
t_node					*create_new_node(t_node_type type);
bool					token_type(t_minishell *token);
bool					ft_is_redir(t_token_type type);
bool					ft_get_io_list(t_io_node **io_list, t_minishell *lst);
bool					ft_join_args(char **args, t_minishell *to_join);
void					parse_err_type(t_pars_err_type type, t_minishell *err);
void					ft_append_io_node(t_io_node **lst, t_io_node *new);
void					handle_parsing_err(void);
void					ft_clear_io_list(t_io_node **lst);
void					ft_get_next_token(t_minishell *next_ptr);
void					ft_clear_cmd_node(t_node *node);
void					ft_recursive_clear(t_node *node);
void					ft_clear_ast(t_node **ast, t_minishell *lst);

#endif