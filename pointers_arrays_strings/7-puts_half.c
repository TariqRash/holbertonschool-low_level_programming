#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: string to print half of
 *
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int start_index;
	int i;

	/* Calculate length of string */
	while (str[length] != '\0')
	{
		length++;
	}

	/* Calculate starting index for second half */
	if (length % 2 == 0)
	{
		start_index = length / 2;
	}
	else
	{
		start_index = (length + 1) / 2;
	}

	/* Print second half of string */
	for (i = start_index; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
