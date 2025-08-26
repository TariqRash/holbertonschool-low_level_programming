#include "main.h"

/**
 * print_times_table - prints the n times table
 * @n: times table to print
 */
void print_times_table(int n)
{
	int row, col, result;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			result = row * col;
			if (col == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				if (result < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
				}
				else if (result < 100)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else
				{
					_putchar(' ');
				}
				if (result >= 100)
					_putchar((result / 100) + '0');
				if (result >= 10)
					_putchar(((result / 10) % 10) + '0');
				_putchar((result % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
