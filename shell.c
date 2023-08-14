#include "shell.h"
/**
 * display_prompt - function to display the shel =l prompt
 *
 */

void display_prompt(void)
{
	printf("MyShell:~$ ");
}

/**
 * main - function to call display_prompt
 *
 * Return: 0.
 */
int main(void)
{
	char user_input[MAX_INPUT_LENGTH];

	while (1)
	{
		display_prompt();
		read_input(user_input, MAX_INPUT_LENGTH);
		process_input(user_input);
	}
	return (0);
}
