/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/23 12:07:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h> 
# include <signal.h>
# include <dirent.h>
# include <unistd.h>
# include <stdbool.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "parsing.h"
# include "libft.h"
# include <errno.h>
# include "parsing.h"
# include "tokenizing.h"

int	sig_pipe[2];

typedef struct s_minishell
{
	char			*line;
	t_token			*tokens;
	t_token			*curr_token;
	int				exit_s;
	t_parse_err		parse_err;
	int				stdin;
	int				stdout;
	char			**environ;
	t_node			*ast;
	t_env			*envlst;
}					t_minishell;

typedef struct	s_signal_handler
{
	bool			heredoc_sgint;
	bool			signint_child;
	struct 	termios	original_term;
	bool			cleanup_needed;
}	t_signal_handler;

t_signal_handler g_sig_handler;

//Builtins functions
void	change_path(t_sysvar *sys_var);
int		change_dir(t_sysvar *sysvar, char *path);
void	add_path_to_env(t_sysvar *sys_var);
int		env(t_sysvar *sys_var);
int		is_digit(char *str);
void	free_sysvar(t_sysvar *sys_var);
void	free_doublearr(char **str);
int		custom_exit(t_sysvar *sys_var, char **args);
int		error_in_export(char *arg);
int		invalid_id(char c);
int		after_eql_sign(char *str);
char	**add_var(char **env, char *argv);
int		custom_export(t_sysvar *sys_var, char **argv);
int		unset(t_sysvar *sys_var, char **args);

#endif