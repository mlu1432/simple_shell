#include "main.h"
/**
 * find_path - Concatenates an input with paths in global variable PATH
 * @path: directory string to be append with the command
 * @command: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *find_path(char *path, char *command)
{
int a, b = 0, length1, length2;
char *new_path = NULL;

if (path == NULL || command == NULL)
return (NULL);

length1 = _strlen(path);
length2 = _strlen(command);
new_path = malloc(length1 + length2 + 2);
if (new_path == NULL)
return (NULL);
for (a = 0; path[a] != '\0'; a++)
{
new_path[a] = path[a];
}
if (path[a - 1] != '/')
{
new_path[a] = '/';
a++;
}
while (command[b] != '\0')
{
new_path[a + b] = command[b];
b++;
}
new_path[a + b] = '\0';
return (new_path);
}
