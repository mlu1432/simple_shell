#include "main.h"
/**
 * check_path - checks if the first command is executable
 * @argu: Array of strings entered by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int check_path(char **argu)
{
char *globalpath = NULL;
char *globaldup = NULL;
char *dirpath = NULL;
char *command_path = NULL;
char *testcph[130];
int exist_status = -1, i = 0;

globalpath = _getenv("PATH");
if (globalpath == NULL)
return (-1);
globaldup = (_strdup(globalpath));
dirpath = strtok(globaldup, ":");
if (dirpath == NULL)
return (-1);
free(globalpath);
while (exist_status == -1 && dirpath != NULL)
{
command_path = find_path(dirpath, argu[0]);
testcph[i] = command_path;
exist_status = file_exist(testcph[i]);
dirpath = strtok(NULL, ":");
i++;
}
i--;
free(globaldup);
free_all(testcph, i);
if (exist_status == 0)
{
argu[0] = testcph[i];
return (0);
}
else
{
free(testcph[i]);
return (-1);
}
}
