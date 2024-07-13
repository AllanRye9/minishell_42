#include "../include/minishell.h"

int ft_strcmp(char *s, char *s1)
{
    int i = 0;
    while(s[i] && s1[i] && s1[i] == s[i])
        i++;
    return (s[i] - s1[i]);
}

char *ft_strcpy(char *d, char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
    return (d);
}

int		ft_execvp(const char *file, char *const argv[])
{
    if (file == NULL || argv == NULL) {
        errno = EINVAL;
        return -1;
    }

    extern char **environ; // environment variables
    const char *path = getenv("PATH");

    if (path == NULL) {
        path = "/bin:/usr/bin"; // fallback path if PATH is not set
    }
    // Try to execute the file directly
    execve(file, argv, environ);
    if (errno != ENOENT) { // execve failed for a reason other than file not found
        return -1;
    }
    // Copy the PATH variable so we can safely modify it
    char *path_copy = ft_strdup(path);
    if (path_copy == NULL) {
        return -1;
    }
    char *dir = ft_strtok(path_copy, ":");
    while (dir != NULL) {
        // Construct the full path
        FILE *memstream;
        char *full_path;
        size_t length;
        memstream = open_memstream(&full_path, &length);
        if (memstream == NULL) {
            free(path_copy);
            return -1;
        }
        fprintf(memstream, "%s/%s", dir, file);
        fclose(memstream);

        // Try to execute the file
        execve(full_path, argv, environ);
        free(full_path);
        if (errno != ENOENT) { // execve failed for a reason other than file not found
            free(path_copy);
            return -1;
        }
        // Try the next directory
        dir = ft_strtok(NULL, ":");
    }
    free(path_copy);
    errno = ENOENT; // No such file or directory found in PATH
    return -1;
}