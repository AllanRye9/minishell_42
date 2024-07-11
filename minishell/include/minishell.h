/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/10 19:04:31 by oallan           ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "libft.h"

#define MAXCOM 1000 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported 

// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 

int             ft_strcmp(char *s, char *s1);
void            check_cd(char *path);
void            printDir();
int             parsePipe(char* str, char** strpiped) ;
void            openHelp();
void            parseSpace(char* str, char** parsed); 
void            execArgs(char** parsed);
int             processString(char* str, char** parsed, char** parsedpipe);
int             takeInput(char* str);
void            execArgsPiped(char** parsed, char** parsedpipe);
int             ownCmdHandler(char** parsed);

#endif