/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:48:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/18 18:44:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef enum	parsing_error_type
{
	MEM_ERROR,
	SYNTAX_ERROR
}	t_pars_err_type;

typedef struct	parsing_err
{
	t_pars_err_type	error_type;
	char			*str;
}	t_parserror;

typedef enum	node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_CMD
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

typedef struct node
{
	t_node_type		node_type;
	t_io_type		*io_type;
	char			*arg;
	char			*expanded_args;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct sys_variable
{
	char			*args;
	t_token			*tokens;
	t_token			*current_token;
	t_node			*node;
	int				exit_status;
	int				sigint_child;
	t_parserror		parsing_error;
	int				stdin;
	int				stdout;
	char			**env;
	char			**path;
	t_env			*env;
	bool			heredoc_sigint;
}	t_sysvar;

#endif