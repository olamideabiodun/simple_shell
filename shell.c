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
int main(void)
{
	char *buff = NULL;
    size_t buff_size = 0;
    ssize_t bytes;

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
        
		process_input(buff);
	}
	free(buff);
	return (0);
}
