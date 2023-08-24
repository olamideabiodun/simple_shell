
#include "shell.h"

/**
 * builtIn - handles built-n commands
 * @input: command
 * @env: env
*/
void builtIn(char **input, char **envp, char *user_input, int *exitStat)
{
    int i = 0;
    if (_strcmp(input[0], "env") == 0 || _strcmp(input[0], "printenv") == 0)
    {
        for (; envp[i] != NULL; i++) {
            write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
            write(STDOUT_FILENO, "\n", 1);
        }
    }
    if (_strcmp(input[0], "exit") == 0)
        {
	    free(user_input);
	    free_string(input);
            exit(*exitStat);
        }
}
