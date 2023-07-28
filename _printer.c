#include "main.h"
/**
 * _printer - writes the character in  in the standard input
 * @buff: Pointer to the string to be printed
 * @size: Length ot the prompt
 * Return: 0 if there is no issues or -1 if fails
 */
int _printer(const char *buff, unsigned int size)
{
int result;

if (isatty(STDIN_FILENO))
{
result = write(1, buff, size);
if (result == -1)
return (-1);
}
return (0);
}
