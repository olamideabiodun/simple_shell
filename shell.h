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
char _getPath(char **envp);
char **split_string(const char *input, char delimiter, size_t *word_count);
void free_string(char **vector, size_t count);
char *_strcat(int n, ...);
int main(int argc, char *argv[], char *envp[]);
int test();
char *_strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _strcpy(char *des, const char *src, size_t des_len);
size_t _strlen(const char *str);
char *_strdup(const char *src);
int _atoi(char *s);
void process_input(char *user_input, char **envp);
char check_file_in_all_paths(char *filename, char *path, struct stat *fileStat);
bool check_file_exec(char *path, struct stat *fileStat);

#endif
