#include "main.h"
/**
 * main - This is a simple shell created by
 * Return: 0 if success
 */
int main(void)
{
ssize_t read = 0;
size_t buffer_size = 0;
char *buffer = NULL, *args[20];
int ct = 1, v = 0, fe = 0, exit_status = 0, is_builtin_result = 0;

_printer("$: ", 3);
read = getline(&buffer, &buffer_size, stdin);
while (read != -1)
{
if (*buffer != '\n')
{
con_args(buffer, args);
if (args[0] != NULL)
{
fe = file_exist(args[0]);
if (fe != 0)
{
v = check_path(args);
if (v == 0)
exit_status = exec_cmd(args), free(buffer), free(*args);
else
{
is_builtin_result = check_blt(args, exit_status);
if (is_builtin_result != 0)
exit_status = not_found(args, ct), free(buffer);
}
}
else
exit_status = exec_cmd(args), free(buffer);
}
else
free(buffer);
}
else if (*buffer == '\n')
free(buffer);
buffer = NULL, ct++;
_printer("$ ", 2), read = getline(&buffer, &buffer_size, stdin);
}
freed(buffer);
return (exit_status);
}
