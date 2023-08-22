#include "shell.h"

/**
 * display_prompt - function to display the shel =l prompt
 *
 */

void display_prompt(void)
{
	char *prompt = "$ ";
    write(STDOUT_FILENO, prompt, 2);
}

/**
 * main - function to call display_prompt
 *
 * Return: 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buff = NULL;
    size_t buff_size = 0;
    ssize_t bytes;
	(void)argc;
	(void)argv;

	while (1)
	{
		display_prompt();

        /** reading input... getting input and putting it in buff, buff_size stores the sise of input*/

        bytes = getline(&buff, &buff_size, stdin);
		/** check if bytes fails and exit*/

		if(bytes == -1)
		{
			free(buff);
            exit(EXIT_FAILURE);
		}
	        
			/** get the length of the stdin*/
        buff_size = _strlen(buff);

		  /** setting the newline character to NULL terminating character */

	    if (buff[buff_size - 1] == '\n')
            buff[buff_size - 1] = '\0';
        
		process_input(buff, envp);
       
	}
     free(buff);
	return (0);
}

/**
 * process_input - process user's input
 * @user_input: pointer to the user_input
 */
void process_input(char *user_input, char **envp)
{
        int i = 0;
        char *token;
        char *path = NULL;
        char **command_args;
        char *path_command;
        struct stat fileStat;
       
        char *goodbye_msg = "Goodbye, exiting shell.\n";

        if (_strcmp(user_input, "exit") == 0)
        {
                write(STDOUT_FILENO, goodbye_msg, 25);
                exit(0);
        }

        for (; envp[i] != NULL; i++)
        {

        if (_strncmp(envp[i], "Path=", 5) == 0 || _strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = envp[i] + 5;
            break;
        }
        }

        if (_strcmp(user_input, "path") == 0)
        {
        if (path != NULL)
        {
           write(STDOUT_FILENO, path, _strlen(path));
           write(STDOUT_FILENO, "\n", 2);
        }
        else
        write(STDOUT_FILENO, "\nNO PATH DETECTED \n", 20);
        }

	token = strtok(user_input, " ");
	if (token != NULL)
	{
        command_args = (char **)malloc(2 * sizeof(char *));
        command_args[0] = _strdup(token);
	command_args[1] = NULL;
		if (check_file_exec(command_args[0], &fileStat))
		{
            _execve(command_args[0], command_args, envp);
        }
        else
        {
        path_command = check_file_in_path(command_args[0], &fileStat, path);
        if (path_command)
        {
            _execve(path_command, command_args, envp);
            free(path_command);
        }
        else
        {
            perror("error: EXECVE");
        }
        }
        free(command_args[0]);
	}
    free(command_args);
}
