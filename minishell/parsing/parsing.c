#include "../include/minishell.h"

// function for parsing command words 
void parseSpace(char* str, char** parsed) 
{ 
	int i;

    i = 0;

	while (i < MAXLIST)
    { 
		parsed[i] = strsep(&str, " "); 

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

	if (ownCmdHandler(parsed)) 
		return 0; 
	else
		return 1 + piped; 
} 
