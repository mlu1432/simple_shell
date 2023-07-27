#include "main.h"
/**
 * launch- starts the shell process
 * @buffer: takes in the buffer input
 * Return: 0
*/
int launch(char *buffer)
{
char **argu;
char *path;
int i;
i = 0;
while (buffer[i] != '\0')
{
    if(buffer[i] == '\n')
    {
        buffer[i] = '\0';
    }
    i++;
}

argu = con_args(buffer, " \n");
if (argu[0] == NULL)
return (0);
if (file_exist(argu[0]))
{
exec_cmd(argu);
}
else
{
path = get_path(argu[0]);
argu[0] = strdup(path);
if(file_exist(argu[0]))
{
exec_cmd(argu);
}else{
    perror("error");
}

}
return (0);
}
