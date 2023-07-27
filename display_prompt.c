#include "main.h"

/**
 * display_prompt- displays the shell
 * Return: return 0 if succesful
*/

int display_prompt(void)
{
size_t buff_count;

int input;
char *buffer;

buff_count = 0;
buffer = NULL;
input = 0;
while (-1)
{
if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
printline("shell: ");
input = getline(&buffer, &buff_count, stdin);
if (input == EOF || input == -1)
{
return (-1);
}
else
{
launch(buffer);
}
}

return (0);
}
