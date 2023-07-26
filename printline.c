#include "main.h"

/**
 * printline- gets a character string and prints it out
 * @string: string to be printed
 * Return: returns void
*/

void printline(char *string)
{

for (; *string != '\0'; string++)
{
_putchar(*string);
}

}
