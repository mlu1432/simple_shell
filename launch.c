#include "main.h"
/**
 * launch- starts the shell process
 * @buffer: takes in the buffer input
 * Return: 0
*/
int launch(char *buffer)
{
char **argu;
char *path;
argu = con_args(buffer, " \n");
if (argu[0] == NULL)
return (0);
if (file_exist(argu[0]))
{
exec_cmd(argu);
}
else
{
path = get_path(argu[0]);
argu[0] = strdup(path);
exec_cmd(argu);
}
return (0);
}

