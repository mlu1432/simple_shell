#include "shell.h"
/**
 * hsh - main new_shell
 * @info: return info struct and  parameter
 * @av: main()'s argument vector
 *
 * Return: a success code is 0 and a failure code is 1.
 */
int hsh(info_t *info, char **av)
{
	ssize_t input_status = 0;
	int built_in_status = 0;

	while (input_status != -1 && built_in_status != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		input_status = get_input(info);
		if (input_status != -1)
		{
			set_info(info, av);
			built_in_status = find_builtin(info);
			if (built_in_status == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (built_in_status == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (built_in_status);
}

/**
 * find_builtin - finds a builtin command
 * @info: return info struct and parameter
 *
 * Return: -1 if the builtin not found,
 *	if builtin is successful, 0 is returned
 *	if builtin found but not successful,the 1
 *	if builtin signals exit(), then 2
 */
int find_builtin(info_t *info)
{
	int j;
	int built_in_status = -1;

	builtin_table builtintbl[] = {
		{"exit", _newexit},
		{"env", _newenv},
		{"help", _newhelp},
		{"history", _newhistory},
		{"setenv", _newsetenv},
		{"unsetenv", _newunsetenv},
		{"cd", _newcd},
		{"alias", _newalias},
		{NULL, NULL}
	};

	for (j = 0; builtintbl[j].type; j++)
		if (_strcmp(info->argv[0], builtintbl[j].type) == 0)
		{
			info->line_count++;
			built_in_status = builtintbl[j].func(info);
			break;
		}
	return (built_in_status);
}

/**
 * find_cmd - finds a command in the PATH
 * @info: return info struct and parameter
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int j;
	int count;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (j = 0, count = 0; info->arg[j]; j++)
		if (!is_delim(info->arg[j], " \t\n"))
			count++;
	if (!count)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - runs cmd by forking an exec thread
 * @info: return info struct and parameter
 *
 * Return: void success
 */
void fork_cmd(info_t *info)
{
	pid_t new_child_pid;

	new_child_pid = fork();
	if (new_child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("An error occurred during command execution:");
		return;
	}
	if (new_child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Wait failed\n");
		}
	}
}
