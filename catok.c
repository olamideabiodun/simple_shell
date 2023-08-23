#include "shell.h"

/**
 *_strcat - concatenates a number of strings
 *@n: number of passed strings
 *Return: Concatenated string
 */

char *_strcat(int n, ...)
{
	int length = 0, x = 0, y = 0, count = n, z = 0;
	char *result;
	char *word;
	va_list args;
	va_start(args, n);

	while (count > 0)
	{
		length += _strlen(va_arg(args, char *));
		count--;
	}

	va_end(args);

	result = (char *) malloc(length + 1);

	if (result == NULL)
	{
		perror("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	count = n;
	va_start(args, n);

	for (; x < count; x++)
	{
		word = va_arg(args, char *);
		while (word[y] != '\0')
		{
			result[z] = word[y];
			y++;
			z++;
		}

		y = 0;
	}

	result[z] = '\0';

	return (result);
}

/**
 *_strtok - used to split springs into tokens
 *@str: string to split
 *@delim: delimiter used to separate strings
 */
char *_strtok(char *str, const char *delim)
{
	static char *newtstart = NULL;
	char *tokenstart;
	bool del = false;
	size_t i = 0;
	char *tend;

	if (str != NULL)
	{
		newtstart = str;
	}
	else if (newtstart == NULL)
	{
		return (NULL);
	}

	tokenstart = newtstart;

	while (*tokenstart != '\0')
	{
		del = false;
		for (; delim[i] != '\0'; i++)
		{
			if (*tokenstart == delim[i])
			{
				del = true;
				break;
			}
		}

		if (!del)
		{
			break;
		}

		tokenstart++;
	}

	if (*tokenstart == '\0')
	{
		newtstart = NULL;
		return (NULL);
	}

	tend = tokenstart + 1;

	while (*tend != '\0')
	{
		del = false;
		for (; delim[i] != '\0'; i++)
		{
			if (*tend == delim[i])
			{
				del = true;
				break;
			}
		}

		if (del)
		{ *tend = '\0';
			tokenstart = tend + 1;
			break;
		}

		tend++;
	}

	if (*tend == '\0')
	{
		newtstart = NULL;
	}

	return (tokenstart);
}
