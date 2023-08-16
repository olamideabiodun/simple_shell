#include "shell.h"

/**
 * _strtok - used to split springs into tokens
 * @str: string to split
 * @delim: delimiter used to separate strings
 */
char *_strtok(char *str, const char *delim)
{
	static char *newtstart = NULL;
	char *tokenstart;
	bool del = false;
	size_t i = 0;

	if (str != NULL)
	{
		newtstart = str;
	}
	else if	(newtstart == NULL);
	return (NULL);

	tokenstart = newtstart;

	while (*tokenstart != '\0')
	{
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

	char *tend = tokenstart + 1;

	while (*tend != '\0')
	{
		for (; delim[i] != '\0'; i++)
		{
			if (*tend == delim[i])
			{
				del = true;
				break;
			}
		}
		if (del)
		{
			*tend = '\0';
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
