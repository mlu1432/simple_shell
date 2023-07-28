#include "main.h"
/**
 *free_all - Free the allocated memory used in the last excercise
*@buffer: pointer to arrat
*@arg_count: number of args
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
