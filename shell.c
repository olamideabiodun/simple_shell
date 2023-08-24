#include "shell.h"

/**
 *display_prompt - function to display the shel =l prompt
 *
 */

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 *main - function to call display_prompt
 *@argc: args count
 *@argv: argv
 *@envp: envp
 *Return: 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buff = NULL;
	size_t buff_size = 0;
	ssize_t bytes;
	(void) argc;
	(void) argv;

	while (1)
	{
		display_prompt();
		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[bytes - 1] == '\n')
		{
			buff[bytes - 1] = '\0';
		}
		process_input(buff, envp);
	}

	free(buff);
	return (0);
}

/**
 *process_input - process user's input
 *@user_input: pointer to the user_input
 *@envp: envp
 */
void process_input(char *user_input, char **envp)
{
	int i = 0, j = 0, arg_count = 0;
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

	token = _strtok(user_input, " ");
	if (token != NULL)
	{
		command_args = (char **) malloc((MAX_ARGS + 1) * sizeof(char *));
		if (command_args == NULL)
		{
			perror("Memory allocation failed");
			return;
		}

		command_args[arg_count] = _strdup(token);
		if (command_args[arg_count] == NULL)
		{
			perror("Memory allocation failed");
			free(command_args);
			return;
		}

		arg_count++;

		while (token != NULL && arg_count < MAX_ARGS)
		{
			token = _strtok(NULL, " ");
			if (token != NULL)
			{
				command_args[arg_count] = _strdup(token);
				if (command_args[arg_count] == NULL)
				{
					perror("Memory allocation failed");
					for (j = 0; j < arg_count; j++)
					{
						free(command_args[j]);
					}

					free(command_args);
					return;
				}

				arg_count++;
			}
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

			for (j = 0; j < arg_count; j++)
			{
				free(command_args[j]);
			}

			free(command_args);
		}
	}
}
