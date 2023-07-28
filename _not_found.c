#include "main.h"
/**
 * not_found -  error messages when a command is not found
 * @args: array of args typed by the user
 * @count:number of times that the shell was executed
 * Return: Exit status
 */
int not_found(char **args, int count)
{
char *shell_name = "hsh";
char *non_shell_name = "./hsh";

if (isatty(STDIN_FILENO))
write(2, shell_name, 3);
else
{
write(2, non_shell_name, 5);
}
write(2, ": ", 2);
print_numbers(count);
write(2, ": ", 2);
write(2, args[0], _strlen(args[0]));
write(2, ": not found\n", 12);
return (127);
}
