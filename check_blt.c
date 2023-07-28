#include "main.h"
/**
 * check_blt - Verify if the input is a builtin
 * @arguments: Pointer to the array of arguments
 * @exit_stat: Current exit status
 * Return: -1 if the command is not a builtin, 0 if it is
 */
int check_blt(char **arguments, int exit_stat)
{
char *builtin[2] = {
"exit",
"env"
};
int i = 0;

while (i < 2)
{
if (_strcmp(arguments[0], builtin[i]) == 0)
break;
i++;
}
if (i == 2)
return (-1);
if (_strcmp(builtin[i], "exit") == 0)
{
free(arguments[0]);
exit(exit_stat);
}
if (_strcmp(builtin[i], "env") == 0)
{
if (environ == NULL)
return (0);
write(1, environ, 1000);
}
return (0);
}
