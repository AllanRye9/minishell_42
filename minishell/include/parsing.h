/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:48:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/11 22:43:12 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef enum tokens
{
	PIPE,
	INPUT_R,
	OUTPUT_R,
	INPUT_DELI,
	OUTPUT_DELI
} t_tokens;

typedef struct lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
}	t_lexer;

typedef struct parser
{
	t_lexer			*lexer_box;
	t_lexer			*redirection;
	int				num_redirection;
	struct s_tools	*tools;
}	t_parser;

typedef struct sys_tools
{
	char			*args;
	char			**paths;
	char			**envp;
	struct s_cmds	*cmds;
	t_lexer			*lexer_box;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				*pid;
	bool			heredoc;
	bool			reset;
}	t_systools;

typedef struct cmds
{
	char		**str;
	int			num_redirect;
	char		*here_doc_fname;
	t_lexer		*redirect;
	struct cmds	*next;
}	t_cmds;

#endif