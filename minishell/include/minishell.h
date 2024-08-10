/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/08/10 23:05:04 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <limits.h>
# include "libft.h"
# include "parsing.h"
# include "tokenization.h"
# include "colors.h"

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

typedef struct	s_signal_handler
{
	bool			heredoc_sgint;
	bool			signint_child;
	struct 	termios	original_term;
	bool			cleanup_needed;
}	t_signal_handler;

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
int				ft_strcmp(const char *a, const char *b);
int				after_eql_sign(char *str);
char			**add_var(char **env, char *argv);
int				custom_export(t_minishell *g_shell, char **argv);
int				unset(t_minishell *g_shell, char **args);
void			ft_update_envlst(char *key, char *value, bool create, t_minishell *g_shell);
//clean function
void			ft_clean(t_minishell *G_shell_);
//signal functions
void			init_signals(void);
void			sigquit_handler(int code);

//execution part
void			init_asttree(t_node *node, t_minishell *g_shell);
void			ft_heredoc(t_io_node *io, int fd[2], t_minishell *g_shell);
void			*ft_garbage_collector(void *ptr, bool clean);
//expander exec
char			**split_doublearr(char const *args);
char			**ft_expand(char *args, t_minishell *g_shell);
void			ft_heredoc_expander(char *args, int fd, t_minishell *g_shell);
char			*handle_empty_quotes(char *args);
void			free_doublearr(char **arr);
void			free_tripearr(char ***arr);
char			**ft_join_str_arrs(char ***arr);
bool			ft_is_valid_char(char c);
char			*ft_get_envlst_val(char *key, t_minishell *g_shell);
char			*ft_handle_dquotes(char *args, size_t *i, t_minishell *g_shell);
char			*ft_handle_squotes(char *args, size_t *i);
char			*ft_handle_arg(char *args, size_t *i);
char			*ft_rm_quotes(char *arg);
bool			ft_match_star(char *pattern, char *args);
bool			is_delimeter(char *deli, char *arg);
bool			ft_contains_asterisk(char *args);
void			*ft_garbage_collector(void *ptr, bool clean);
int				ft_exec_node(t_node *tree, bool piped, t_minishell *g_shell);
t_path			ft_get_path(char *cmd, t_minishell *g_shell);
int				ft_exec_cmd(t_node *node, bool piped, t_minishell *g_shell);
size_t			ft_match_count(char *pattern);

//error
t_err			ft_check_exec(char *file, bool cmd);
int				ft_err_msg(t_err err);
int				ft_get_exitstatus(int status);

//builtin
bool			ft_is_builtin(char *arg);
int				ft_exec_builtin(char **args, t_minishell *g_shell);
t_err			ft_check_read(char *file);
t_err			ft_check_write(char *file);
int				ft_check_key(char *str);

//in&out
int				ft_in(t_io_node *io_list, int *status);
int				ft_out(t_io_node *io_list, int *status);
int				ft_append(t_io_node *io_list, int *status);

char			*ft_extract_key(char *str);
bool			ft_env_entry_exist(char *key, t_minishell *g_shell);
char			*ft_extract_value(char *str);

void 			ft_clear_astree(t_node **astree, t_minishell *g);
char	*ft_handle_dollar(char *args, size_t *i, t_minishell *g_shell);

//commands

int				ft_cd(t_minishell *g_shell, char *path);
int 			ft_echo(char** args);
int				ft_env(t_minishell *g_shell);
void			ft_exit(t_minishell *g_shell, char **args);
int				ft_export(t_minishell *g_shell, char **argv);
int				ft_pwd(void);
int				ft_unset(t_minishell *g_shell, char **args);

void			ft_init_envlst(t_minishell *g_shell);
size_t			ft_str_arr_len(char **args);

#endif
