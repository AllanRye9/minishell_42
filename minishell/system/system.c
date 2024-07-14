#include "../include/minishell.h"

void execArgs(char** parsed, ExitStatuses* exitStatuses) 
{ 
    // Forking a child 
    pid_t pid = fork(); 

    if (pid == -1) 
    { 
        printf("\nFailed forking child.."); 
        exitStatuses->lastExitStatus2 = exitStatuses->lastExitStatus1;
        exitStatuses->lastExitStatus1 = 1;
        return; 
    } 
    else if (pid == 0) 
    { 
        // In child process
        if (ft_execvp(parsed[0], parsed) == -1) 
        { 
            printf("bash: %d: command not found\n", 0);  
            exit(EXIT_FAILURE); 
        } 
    } 
    else 
    { 
        // In parent process
        int status;
        waitpid(pid, &status, 0); // Waiting for child to terminate
        
        // Checking the exit status
        if (WIFEXITED(status)) 
        {
            exitStatuses->lastExitStatus2 = exitStatuses->lastExitStatus1;
            exitStatuses->lastExitStatus1 = WEXITSTATUS(status);
        }
        else 
        {
            exitStatuses->lastExitStatus2 = exitStatuses->lastExitStatus1;
            exitStatuses->lastExitStatus1 = 1; // Non-normal termination
        }
        return; 
    } 
}

void handleEcho(char** parsed, ExitStatuses* exitStatuses)
{
    if (strcmp(parsed[0], "echo") == 0 && strcmp(parsed[1], "$?") == 0 && parsed[2] == NULL)
        printf("%d\n", exitStatuses->lastExitStatus1);
    else if (strcmp(parsed[0], "expr") == 0 && strcmp(parsed[1], "$?") == 0 && strcmp(parsed[2], "+") == 0 && strcmp(parsed[3], "$?") == 0 && parsed[4] == NULL)
    {
        printf("%d\n", exitStatuses->lastExitStatus1 + exitStatuses->lastExitStatus2);
    }
}
