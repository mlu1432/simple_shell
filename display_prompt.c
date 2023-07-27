#include "main.h"

/**
 * display_prompt- displays the shell
 * Return: return 0 if succesful
*/

int display_prompt(void)
{
size_t buff_count;
char *path, *buffer, **argu;
int input;

buff_count = 0;
buffer = NULL;
input = 0;
while (-1)
{
if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
printline("shell: ");
getline(&buffer, &buff_count, stdin);
if (input == EOF || input == -1)
{
return (-1);
}
else
{
argu = con_args(buffer, " \n");
if (argu[0] == NULL)
{
continue;
}
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
}
}
free(path);
free_pointer(argu);
free(buffer);
return (0);
}
