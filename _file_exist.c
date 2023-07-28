#include "main.h"
/**
 * exist - Verify if a file exist
 * @path: path to the file
 * Return: 0 if the file exist or -1 if not
 */
int file_exist(char *path)
{
	int exist_status;

	exist_status = (open(path, O_RDONLY));
	if (exist_status != -1)
	{
		close(exist_status);
		return (0);
	}
	else
		return (-1);
}
