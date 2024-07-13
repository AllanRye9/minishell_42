#include "../include/minishell.h"

char *ft_strtok(char *s, char *delim)
{
    static char *save_ptr;
    char *start;
    char *end;

    // If __s is not NULL, we are starting a new string
    if (s != NULL) {
        start = s;
    } else {
        // Otherwise, continue from where we left off
        start = save_ptr;
        if (start == NULL) {
            // If there is no more string left to process, return NULL
            return NULL;
        }
    }
    // Skip initial delimiters
    start += ft_strspn(start, delim);
    if (*start == '\0') {
        // No more tokens
        save_ptr = NULL;
        return NULL;
    }
    // Find the end of the token
    end = start + ft_strcspn(start, delim);
    if (*end != '\0') {
        // Null-terminate the token
        *end = '\0';
        save_ptr = end + 1;
    } else {
        // This is the last token
        save_ptr = NULL;
    }
    return start;
}