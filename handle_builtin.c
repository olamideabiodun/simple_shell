
#include "shell.h"

/**
 * builtIn - handles built-n commands
 * @input: command
 * @env: env
*/
void builtIn(char **input, char **envp)
{
    int i = 0;
    int status;
    char *goodbye_msg = "Goodbye, exiting shell.\n";
    if (_strcmp(input[0], "env") == 0 || _strcmp(input[0], "printenv") == 0)
    {
      for (; envp[i] != NULL; i++)
	{
	write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
	write(STDOUT_FILENO, "\n", 1);
	}
    }
    if (_strcmp(input[0], "exit") == 0)
      {
	if (input[1] != NULL)
	  {
	    status = _atoi(input[1]);
	    write(STDOUT_FILENO, goodbye_msg, 25);
	    exit(status);
	  }
}
