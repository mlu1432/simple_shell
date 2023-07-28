#include "main.h"
/**
 * con_args - converts a line to an array.
 * @string: String with the input
 * @arguments: Array to be filled
 * Return: Length of the array
 */

int con_args(char *string, char **arguments)
{
	int i = 0;
	char *options, *aux = string, *command;

	command = strtok(string, "\n\t\r ");
	arguments[i] = command;
	while (aux != NULL)
	{
		++i;
		options = strtok(NULL, "\n\t\r ");
		aux = options;
		arguments[i] = options;
	}
	arguments[i] = NULL;
	return (i);
}
