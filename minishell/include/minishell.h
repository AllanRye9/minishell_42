/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/11 22:07:09 by sbartoul         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "libft.h"
# include <errno.h>

#define MAXWORDS 1000 // max number of letters to be supported
#define MAXCMD 100 // max number of commands to be supported

// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 


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
#endif