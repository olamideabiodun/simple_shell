#include "shell.h"

/**
 *display_prompt - function to display the shel =l prompt
 *
 */

void display_prompt(void)
{
	char *prompt = "$ ";
	write(STDOUT_FILENO, prompt, 2);
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
	int interactive_mode = isatty(STDIN_FILENO);
	int exitStat = 0;
	int valid_cmd = 0;
	size_t buff_size = 0;
	unsigned int  c_count = 0;
	ssize_t bytes;
	(void) argc;
	(void) argv;
	
	while (1)
	{
	  if(interactive_mode)
	    {
	      display_prompt();
	    }
		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
		  free(buff);
		  exit(exitStat);
		}
		c_count++;

		buff_size = _strlen(buff);
		if (buff[buff_size - 1] == '\n')
			buff[buff_size - 1] = '\0';
		if (buff_size > 0)
		  {
		    process_input(buff, argv, envp, c_count, &exitStat, &valid_cmd);
		  }
		free(buff);
		buff = NULL;
	}

	free(buff);
	return (0);
}

/**
 *process_input - process user's input
 *@user_input: pointer to the user_input
 *@envp: envp
 */
void process_input(char *user_input, char **argv, char **envp, unsigned int c_count, int *exitStat, int *valid_cmd)
{
	int i = 0, j = 0, arg_count = 0;
	size_t input_length;
	char *token;
	char *path = NULL;
	char *c_count_str;
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
		command_args = (char **) malloc((MAX_ARGS + 1) * sizeof(char *));
		if (command_args == NULL)
		{
			perror("Memory allocation failed");
			for (j = 0; j < arg_count; j++)
				free(command_args[j]);
			free(command_args);
			return;
		}

		command_args[arg_count] = _strdup(token);
		if (command_args[arg_count] == NULL)
		{
			perror("Memory allocation failed");
			for (j = 0; j < arg_count; j++)
				free(command_args[j]);
			free(command_args);
			return;
		}

		arg_count++;

		while (token != NULL && arg_count < MAX_ARGS)
		{
			token = strtok(NULL, " ");
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
		  builtIn(command_args, envp, user_input, exitStat);
		       if (check_file_exec(command_args[0], &fileStat, valid_cmd))
			 _execve(command_args[0], command_args, envp, exitStat);
			else
			{
			  path_command = check_file_in_path(command_args[0], &fileStat, path, valid_cmd);
				if (path_command)
				{
				  *exitStat = 0;
				  _execve(path_command, command_args, envp, exitStat);
				free(path_command);
				}
				else
				  {
				    c_count_str = intTOstr(c_count);
				    *exitStat = 127;
				    printerr(argv[0], c_count_str, command_args[0], ": not found");
				    free(c_count_str);
 
				  }
			}

			for (j = 0; j < arg_count; j++)
				free(command_args[j]);

			free(command_args);
		}
        
	free(token);
	input_length = strlen(user_input);
    if (input_length > 0 && user_input[input_length - 1] == '\n') {
        user_input[input_length - 1] = '\0';
    }
}
}
