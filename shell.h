#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void display_prompt(void);
int _strlen(char *c);
int _strcmp(const char *str1, const char *str2);

#define MAX_INPUT_LENGTH 100

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
 * process_input - process user's input
 * @user_input: pointer to the user_input
 */
void process_input(const char *user_input)
{
	char *goodbye_msg = "Goodbye, exiting shell.\n";
        if (_strcmp(user_input, "exit") == 0)
        {
                write(STDOUT_FILENO, goodbye_msg, 25);
                exit(0);
        }
}

#endif
