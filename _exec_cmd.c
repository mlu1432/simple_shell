#include "main.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec_cmd(char **arguments)
{
	pid_t pid = 0;
	int status = 0, exe_status = 0;

	pid = fork();
	if (pid == -1)
		_printer("failed\n", 7);
	else if (pid == 0)
	{
		exe_status = execve(arguments[0], arguments, environ);
		if (exe_status == -1)
		{
			exe_status = 126;
			perror("hsh");
			exit(exe_status);
		}
		exit(0);
	}
	else
		wait(&status);
	exe_status = WEXITSTATUS(status);
	return (exe_status);
	}
