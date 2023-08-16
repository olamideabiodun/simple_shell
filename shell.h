#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <sys/stat.h>

#define MAX_INPUT_LENGTH 100

void display_prompt(void);
int _strlen(char *c);
int _strcmp(const char *str1, const char *str2);
char _getPath(char **envp);
char **split_string(const char *input, char delimiter, size_t *word_count);
void free_string(char **vector, size_t count);
char *_strcat(int n, ...);
char *_strtok(char *str, const char *delim);

/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 for success
 */
int _strcmp(const char *str1, const char *str2)
{
        while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

/**
 * _strncmp - compares n number of chars between two strings
 * @s1: string 1
 * @s2: string 2
 * @n: characters count 
 * Return: 0 for equal, !0 otherwise
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
    for (;n > 0 && *s1 && (*s1 == *s2); n--, s1++, s2++)
        ;
    if (n == 0)
    return (0);

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

/**
 * _strcpy - copies one string to another
 * @des: destination
 * @src: source
 * @des_len: destination size
 */
void _strcpy(char *des, const char *src, size_t des_len)
{
	size_t i = 0;

	while (*src != '\0' && i < des_len -1)
	{
		*des = *src;
		des++;
		src++;
		i++;
	}
	*des = '\0';
}

/**
 * _strlen - counts the length of string
 * @str: string to count
 *
 * Return: counts
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strdup - duplicates a string
 * @src: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(const char *src)
{
	if (src == NULL)
		return (NULL);

	size_t len = _strlen(src) + 1;
	char *des = (char *)malloc(len);

	if (*des != NULL)
	{
		_strcpy(des, src);
	}
	return (des);
}
/**
 * process_input - process user's input
 * @user_input: pointer to the user_input
 */
void process_input(const char *user_input, char **envp)
{
        int i = 0;
        char *path = NULL;
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
        
}

#endif
