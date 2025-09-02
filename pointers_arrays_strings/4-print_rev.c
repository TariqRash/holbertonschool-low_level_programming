#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: string to print in reverse
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	/* Calculate length of string */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Print string in reverse */
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
