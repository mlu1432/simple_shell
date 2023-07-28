#include "main.h"
/**
 * main - This is a simple shell created by
 * Return: 0 if success
 */
int main(void)
{
	ssize_t read = 0;
	size_t buffer_size = 0;
	char *buffer = NULL, *args[20];
	int counter = 1, verify = 0, file_exists = 0, exit_stat = 0, is_builtin_result = 0;

	_print("$: ", 3);
	read = getline(&buffer, &buffer_size, stdin);
	while (read != -1)
	{
		if (*buffer != '\n')
		{
			con_args(buffer, args);
			if (args[0] != NULL)
			{
				file_exists = file_exist(args[0]);
				if (file_exists != 0)
				{
					verify = verify_path(args);
					if (verify == 0)
						exit_stat = exec_cmd(args), free(buffer), free(*args);
					else
					{
					is_builtin_result = verify_blt(args, exit_stat);
					if (is_builtin_result != 0)
						exit_stat = print_not_found(args, counter), free(buffer);
					}
				}
				else
					exit_stat = exec_cmd(args), free(buffer);
			}
			else
				free(buffer);
		}
		else if (*buffer == '\n')
			free(buffer);
		buffer = NULL, counter++;
		_print("$ ", 2), read = getline(&buffer, &buffer_size, stdin);
	}
	last_free(buffer);
	return (exit_stat);
}
