#include "main.h"
/**
 * _strlen - returns the length of a string
 * @string: String to be sized
 * Return: The length ot the string
 */

int _strlen(const char *buffer)
{
	int i = 0;

	if (buffer == NULL)
		return (0);

	while (buffer[i] != '\0')
		i++;
	return (i);
}
