#include "main.h"

/**
 * con_args- converts a string to arguments;
 *@line: takes a string.
  *@delim: deliminter.
* Return: returns an array.
*/

char **con_args(char *line, char *delim)
{
int i;
char **tokens;
char *token;
int length;
int position = 0;
length = strlen(line);
tokens = malloc(sizeof(char *) * length);
token = NULL;

while (token != NULL)
{
position++;
token = strtok(NULL, delim);
}
position++;

token = strtok(line, delim);

for (i = 0; token != NULL; i++)
{
tokens[i] = malloc(sizeof(char) * strlen(token));
strcpy(tokens[i], token);

token = strtok(NULL, delim);
}
tokens[i] = NULL;
free(token);
return (tokens);
}

