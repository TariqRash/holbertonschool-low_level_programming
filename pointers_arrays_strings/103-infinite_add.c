#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * reverse_string - reverses a string in place
 * @str: string to reverse
 * @len: length of string
 *
 * Return: void
 */
void reverse_string(char *str, int len)
{
	int i;
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

/**
 * infinite_add - adds two numbers
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result or 0 if can't store
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, i, j, k, carry, sum;

	len1 = _strlen(n1);
	len2 = _strlen(n2);

	if (len1 >= size_r || len2 >= size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	k = 0;
	carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		if (k >= size_r - 1)
			return (0);

		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}

	r[k] = '\0';
	reverse_string(r, k);

	return (r);
}
