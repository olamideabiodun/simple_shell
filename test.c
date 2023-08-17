#include "shell.h"

/**
 * main - tests all functions
 *
 * Return: Always 0, Success.
 */
int main(void)
{
	char input[] = {"ball,car,dog,tarek,faruq"};
	const char *del[] = {","};

	char *token = _strtok(input, *del);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, *del);
	}
	return (0);
}
