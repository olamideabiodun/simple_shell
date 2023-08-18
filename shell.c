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
        char **args;
        char *path = NULL;
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

       args = _strtok(user_input, " ");
       check_file_exec(args[0], &fileStat);

       
    free(args);
}
