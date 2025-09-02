#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: integer value of string
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int digit_found = 0;

	/* Skip initial whitespace and count signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = -sign;
		}
		else if (s[i] == '+')
		{
			/* Just move to next character */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_found = 1;
			/* Build result with sign applied directly */
			if (sign == 1)
			{
				result = result * 10 + (s[i] - '0');
			}
			else
			{
				result = result * 10 - (s[i] - '0');
			}
		}
		else if (digit_found)
		{
			/* Stop if we hit non-digit after finding digits */
			break;
		}
		/* Skip other characters if no digits found yet */
		i++;
	}

	return (result);
}
