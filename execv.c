#include "shell.h"

/**
 * check_file_exec - checks if the file exists
 * @file: path of the file
 * @fileStat: stores info about the file if it exists
 * Return: true for success, false otherwise
*/

bool check_file_exec(char *file, struct stat *fileStat)
{
int status;
status = stat(file, fileStat);
if (status == 0)
{
return (true);
}
return (false);
}

char *check_file_in_path(char *filename, struct stat *fileStat, char *path)
{

char *full_path;
char *token_copy = _strdup(path);
char *token = strtok(token_copy, ":");

while (token != NULL)
    {
        full_path = _strcat(3, token, "/", filename);
	 
        if (check_file_exec(full_path, fileStat))
        {
	    free(token_copy);
        return full_path;
        }
	free(full_path);
	token = strtok(NULL, ":");
    }

free(token_copy);
return (NULL);
}

int _execve(char *path, char **commands, char **envp)
{
    int status;
    pid_t child_process;

    child_process = fork();
    if (child_process == -1)
    {
        perror("Error: Fork");
        exit(EXIT_FAILURE);
    }
    if (child_process == 0)
	    execve(path, commands, envp);

    if (waitpid(child_process, &status, 0) == -1)
    {
        perror("Error: Fork");
        exit(EXIT_FAILURE);
    }
return (0);
}
