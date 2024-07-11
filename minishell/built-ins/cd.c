#include "../include/minishell.h"

// Function to print Current Directory. 
void printDir() 
{ 
	char cwd[1024]; 
	getcwd(cwd, sizeof(cwd)); 
	printf("@%s %s", getenv("USER"), cwd); 
} 