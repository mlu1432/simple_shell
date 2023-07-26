#include "main.h"


/**
 * exec_cmd - takes an argument and executes the funnction
 * @filepath: the file path
 * Return: returns 1 if it fails
*/
void exec_cmd(char **filepath)
{
int id;
int status;
status = 0;
id = fork();
if (id == 0)
{
if (execve(filepath[0], filepath, environ) == -1)
{
perror("ERROR");
}
}
else
{
wait(&status);
}
}
