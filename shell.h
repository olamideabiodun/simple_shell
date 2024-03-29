#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 100


void display_prompt(void);
char _getPath(char **envp);
char **split_string(const char *input, char delimiter, size_t *word_count);
void free_string(char **vector);
char *_strcat(int n, ...);
int main(int argc, char *argv[], char *envp[]);
int test(void);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _strcpy(char *des, const char *src, size_t des_len);
size_t _strlen(const char *str);
char *_strdup(const char *src);
int _atoi(char *s);
void process_input(char *user_input, char **argv,  char **envp, unsigned int c_count, int *exitStat, int *valid_cmd);
char *check_file_in_path(char *filename, struct stat *fileStat, char *path, int *valid_cmd);
bool check_file_exec(char *file, struct stat *fileStat, int *valid_cmd);
int _execve(char *path, char **commands, char **envp, int *exitStat);
char *strtok_custom(char *str, const char *delim);
void builtIn(char **input, char **envp, char *user_input, int *exitStat, unsigned int c_count);
void printerr(char *prgm, char *cmd_C, char *cmd, char *err);
void exitErr(char *prgm, int c_count, char *msg, char *err, char *arg1);
char *intTOstr(unsigned int n);
char *_getenv(const char *name);
#endif
