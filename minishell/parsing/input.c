#include "../include/minishell.h"

// Function to take input 
int takeInput(char* str) 
{ 
	char* buf; 

	buf = readline("$ "); 
	if (ft_strlen(buf) != 0) { 
		add_history(buf); 
		ft_strcpy(str, buf); 
		return 0; 
	} else { 
		return 1; 
	} 
} 