#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void display_prompt(void);

#define MAX_INPUT_LENGTH 100

/**
 * read_input - read user's input
 * @buffer: pointer to cahracter array
 * @max_length: maximum numbber of characters that can be read
 */
void read_input(char *buffer, int max_length)
{
	fgets(buffer, max_length, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
}


/**
 * process_input - process user's input
 * @user_input: pointer to the user_input
 */
void process_input(const char *user_input)
{
	char *goodbye_msg = "Goodbye, exiting the shell.\n";
        if (strcmp(user_input, "exit") == 0)
        {
                write(STDOUT_FILENO, goodbye_msg, 2);
                exit(0);
                printf("%s\n", user_input);
        }
}

#endif
