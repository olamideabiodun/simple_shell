#include "shell.h"

/**
 * display_prompt - function to display the shel =l prompt
 *
 */

void display_prompt(void)
{
	char *prompt = "$ ";
    write(STDOUT_FILENO, prompt, 2);
}

/**
 * main - function to call display_prompt
 *@argc: args count
 *@argv: argv
 *@envp: envp
 * Return: 0.
 */
int main(int argc, char *argv[], char *envp[])
{
char *buff = NULL;
size_t buff_size = 0;
ssize_t bytes;
(void)argc;
(void)argv;

while (1)
{
display_prompt();
bytes = getline(&buff, &buff_size, stdin);
if (bytes == -1)
{
free(buff);
exit(EXIT_FAILURE);
}
buff_size = _strlen(buff);
if (buff_size > 0 && buff[buff_size - 1] == '\n')
{
buff[buff_size - 1] = '\0';
}

process_input(buff, envp);
buff_size = 0;
}
free(buff);
return (0);
}

/**
 * process_input - process user's input
 * @user_input: pointer to the user_input
 * @envp: envp
 */
void process_input(char *user_input, char **envp)
{
int i = 0, j = 0, arg_count;
char *token;
char *path = NULL;
char **command_args;
char *path_command;
struct stat fileStat;
for (; envp[i] != NULL; i++)
{
if (_strncmp(envp[i], "Path=", 5) == 0 || _strncmp(envp[i], "PATH=", 5) == 0)
{
path = envp[i] + 5;
break;
}
}

token = strtok(user_input, " ");
if (token != NULL)
{
command_args = (char **)malloc(MAX_ARGS * sizeof(char *));
arg_count = 0;
command_args[0] = _strdup(token);
command_args[1] = NULL;
while (token != NULL && arg_count < MAX_ARGS - 1)
{
command_args[arg_count] = _strdup(token);
arg_count++;
token = strtok(NULL, " ");
}
command_args[arg_count] = NULL;
if (arg_count > 0)
{
builtIn(command_args, envp);
if (check_file_exec(command_args[0], &fileStat))
_execve(command_args[0], command_args, envp);
else
{
path_command = check_file_in_path(command_args[0], &fileStat, path);
if (path_command)
{
_execve(path_command, command_args, envp);
free(path_command);
}
else
perror("error: EXECVE");
}
}
for (; j < arg_count; j++)
free(command_args[j]);
}
free(command_args);
}
