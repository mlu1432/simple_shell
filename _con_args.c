#include "main.h"
/**
 * con_args - converts a line to an array.
 * @string: String with the input
 * @args: an Array to be filled by strtok
 * Return: Length of the array
 */

int con_args(char *string, char **args)
{
int i = 0;
char *opt, *token = string, *command;

command = _strtok(string, "\n\t\r ");
args[i] = command;
while (token != NULL)
{
++i;
opt = _strtok(NULL, "\n\t\r ");
token = opt;
args[i] = opt;
}
args[i] = NULL;
return (i);
}
