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
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "parsing.h"
# include "libft.h"
# include <errno.h>
# include "parsing.h"
# include "tokenizing.h"

# define MAXWORDS 1000 // max number of letters to be supported
# define MAXCMD 100 // max number of commands to be supported
# define STDERR 2
// Clearing the shell using escape sequences 
# define clear() printf("\033[H\033[J") 
# define STDERR 2

// Structure to hold the last two exit statuses
typedef struct {
    int lastExitStatus1;
    int lastExitStatus2;
} ExitStatuses;

int             ft_strcmp(char *s, char *s1);
int             parsePipe(char* str, char** strpiped) ;;
void            parseSpace(char* str, char** parsed);
char*           ft_strsep(char **str, char c);
char*           ft_strchr(const char *str, int c);
void            execArgs(char** parsed, ExitStatuses* exitStatuses);
void            handleEcho(char** parsed, ExitStatuses* exitStatuses);
void            ft_echo(char **args);
int             processString(char* str, char** parsed, char** parsedpipe);
int             takeInput(char* str);
void            execArgsPiped(char** parsed, char** parsedpipe);
int             CmdHandler(char** parsed);
int             ft_execvp(const char *file, char *const argv[]);
size_t          ft_strchar(char *s, char c);
char            *ft_strcpy(char *d, char *s);
char            *ft_strtok(char *s, char *delim);
size_t          ft_strspn(char *start, char *delim);
size_t          ft_strcspn(char *start, char *delim);
//signal handling.
void	sig_handler(int code);


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