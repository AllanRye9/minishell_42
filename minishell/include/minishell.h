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
# include <signal.h>
# include <dirent.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "libft.h"

int             ft_strcmp(char *s, char *s1);
void            check_cd(char *path);
void            pwd_check(char *path);
#endif