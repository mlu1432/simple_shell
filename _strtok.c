#include "main.h"

/**
 * _strtok- breaks a string
 * @str: string passed
 * @delim: delimiter
 * Return: a new array
*/

char *_strtok(char *str, char *delim)
{
static char *s;
int i;
char *token;

if (str != NULL)
s = str;


for (; *s != '\0'; s++)
{
for (i = 0; delim[i] != '\0'; i++)
{
if (*s == delim[i])
break;
}
if (delim[i] == '\0')
break;
}


token = s;
if (*token == '\0')
return (NULL);


for (; *s != '\0'; s++)
{
for (i = 0; delim[i] != '\0'; i++)
{
if (*s == delim[i])
{
*s = '\0';
s++;
return (token);
}
}
}

return (token);
}
