#include "main.h"
/**
 * exec_cmd - Starts the process.
 * @args: Array of inputs by the user
 * Return: 0 if success
 */
int exec_cmd(char **args)
{
pid_t pid = 0;
int status = 0, exe_status = 0;

pid = fork();
if (pid == -1)
_printer("failed\n", 7);
else if (pid == 0)
{
exe_status = execve(args[0], args, environ);
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
