#include "main.h"
/**
 *free_grid - Free the allocated memory used in the last excercise
 *@grid: pointer to grid
 *@heigth: Heigth of the grid
 */

void free_all(char **buffer, int arg_count)
{
	int i = 0;

	if (buffer == NULL)
	{
		return;
	}

	while (i < arg_count)
	{
		free(buffer[i]);
		i++;
	}
}
