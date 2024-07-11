#include "../include/minishell.h"

int ft_strcmp(char *s, char *s1)
{
    int i = 0;
    while(s[i] && s1[i] && s1[i] == s[i])
        i++;
    return (s[i] - s1[i]);
}

// Help command builtin 
void openHelp() 
{ 
	puts("\n***MINISHELL HELP TOOLKITS***"
		"\nCopyright @ Suprotik Dey"
		"\n-Use the shell at your own risk..."
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>exit"
		"\n>all other general commands available in UNIX shell"
		"\n>pipe handling"
		"\n>improper space handling"); 

	return; 
} 
