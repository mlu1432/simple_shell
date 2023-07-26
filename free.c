#include "main.h"

/**
 * free_pointer- frees an argument
 * @arr: the array
 * Return: returns nothing
*/

void free_pointer(char **arr)
{
int i = 0;

while (arr[i])
free(arr[i++]);
free(arr);
}
