#include "main.h"


/**
 * file_exist- checks if a file exist
 * @filepath: the file path to be checked.
 * Return: returns 0 if true and 1 if false.
*/
int file_exist(char *filepath)
{

struct stat buffer;

if (stat(filepath, &buffer))
return (0);

return (1);
}










