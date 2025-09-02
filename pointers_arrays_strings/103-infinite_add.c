#include "main.h"

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
	int len1 = 0, len2 = 0, i, j, k, carry = 0, sum;

	/* Calculate lengths */
	while (n1[len1])
		len1++;
	while (n2[len2])
		len2++;

	/* Check if result fits in buffer */
	if (len1 >= size_r || len2 >= size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	k = 0;

	/* Add from right to left */
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

	/* Reverse the result */
	r[k] = '\0';
	for (i = 0; i < k / 2; i++)
	{
		char temp = r[i];
		r[i] = r[k - 1 - i];
		r[k - 1 - i] = temp;
	}

	return (r);
}
