#include "shell.h"

/**
 * _strlen - returns number of chars
 * @c: string
 * Return: Success
 */
int _strlen(char *c)
{
        int x = 0;
        for (; c[x] != '\0'; x++)
        ;
        return (x);    
}

/**
 * _strcat - concatenates a number of strings
 * @n: number of passed strings
 * Return: Concatenated string
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
        
        result = (char*)malloc(length + 1);

	if (result == NULL) {
		perror("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
        count = n;
        va_start(args, n);
  
        for (; x < count; x++)
        {
           word = va_arg(args, char*);
           while (word[y] != '\0')
           {
            result[z] = word[y];
            y++;
            z++;
           }
           y = 0;
        }
        result[z] = '\0';
        
    return result;
}
