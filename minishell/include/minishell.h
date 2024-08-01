/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
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
# include "tokenization.h"

# define PROMPT "minishell$ "
int		sig_pipe[2];

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUI
}	t_err_msg;

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}	t_err_no;

typedef enum e_ast_direction
{
	TD_LEFT,
	TD_RIGHT
}	t_ast_direction;

typedef struct s_err
{
	t_err_no	no;
	t_err_msg	msg;
	char		*cause;
}	t_err;

typedef struct s_path
{
	t_err	err;
	char	*path;
}	t_path;

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
void			free_sysvar(t_minishell *g_shell);
void			free_doublearr(char **str);
void			change_path(t_minishell *g_shell);
void			add_path_to_env(t_minishell *g_shell);
int				change_dir(t_minishell *g_shell, char *path);
int				env(t_minishell *g_shell);
int				is_digit(char *str);
int				custom_exit(t_minishell *g_shell, char **args);
int				error_in_export(char *arg);
int				invalid_id(char c);
int				after_eql_sign(char *str);
char			**add_var(char **env, char *argv);
int				custom_export(t_minishell *g_shell, char **argv);
int				unset(t_minishell *g_shell, char **args);
//clean function
void			ft_clean(t_minishell *G_shell_);
//signal functions
void			init_signals(void);
void			sigquit_handler(int code);
#endif
