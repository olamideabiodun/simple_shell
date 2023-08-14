#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void display_prompt(void);
int _strlen(char *c);

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
int _strcmp(const char *str1, const char *str2);
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
 * read_input - read user's input
 * @buffer: pointer to cahracter array
 * @max_length: maximum numbber of characters that can be read
 */
void read_input(char *buffer, int max_length)
{
        int i = 0;
        int buff_size;
	fgets(buffer, max_length, stdin);
        buff_size = _strlen(buffer);
	for (; i < buff_size; i++)
        {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            break;
        }
        }
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
