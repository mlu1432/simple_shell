#include "main.h"
/**
 * _freed - Free the memory for the last execution
 * @entry: Input typed by the user
 */
void freed(char *buffer)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(buffer);
	}
	if (!isatty(STDIN_FILENO))
		free(buffer);
}
