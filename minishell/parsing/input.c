#include "../include/minishell.h"

// Function to take input 
int takeInput(char* str) 
{ 
	char* buf;

	buf = readline(">>> ");
	while (*buf && (*buf == ' ' || *buf == '\t' || *buf == '\n'))
		buf++;
	if (ft_strlen(buf) != 0)
	{ 
		add_history(buf); 
		ft_strcpy(str, buf);
		return 0; 
	}
	else 
		return 1; 
} 