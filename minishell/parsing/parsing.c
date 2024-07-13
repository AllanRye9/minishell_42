#include "../include/minishell.h"

// function for parsing command words 
void parseSpace(char* str, char** parsed) 
{ 
	int i;

    i = 0;

	while (i < MAXCMD)
    { 
		parsed[i] = ft_strsep(&str, 32); 

		if (parsed[i] == NULL) 
			break; 
		if (ft_strlen(parsed[i]) == 0) 
			i--; 
        i++; 
	} 
} 


int parsePipe(char* str, char** strpiped) 
{ 
    int i; 

	i = 0;
    while(i < 2)
	{ 
        strpiped[i] = strsep(&str, "|"); 
        if (strpiped[i] == NULL) 
            break; 
		i++;
    } 
  
    if (strpiped[1] == NULL) 
        return 0; // returns zero if no pipe is found. 
    else { 
        return 1; 
    } 
} 

int processString(char* str, char** parsed, char** parsedpipe) 
{ 

	char* strpiped[2]; 
	int piped = 0; 

	piped = parsePipe(str, strpiped); 

	if (piped) { 
		parseSpace(strpiped[0], parsed); 
		parseSpace(strpiped[1], parsedpipe); 

	} else { 

		parseSpace(str, parsed); 
	} 

	if (CmdHandler(parsed)) 
		return 0; 
	else
		return 1 + piped; 
} 

// Function to split a string by a delimiter character and return the next token
char* ft_strsep(char **str, char c) {
    char *start = *str; // Start of the string
    char *ptr;

    if (!start) {
        return NULL; // If str is NULL, there is no token to return
    }

    // Find the delimiter in the string
    ptr = ft_strchr(start, c);
    if (ptr) {
        *ptr = '\0';  // Replace delimiter with null character to terminate the token
        *str = ptr + 1; // Move the pointer to the character after the delimiter
    } else {
        *str = NULL; // No more tokens
    }

    return start; // Return the token
}