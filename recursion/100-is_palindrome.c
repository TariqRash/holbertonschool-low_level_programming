#include "main.h"

/**
 * str_len - get string length
 * @s: string
 *
 * Return: length
 */
int str_len(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + str_len(s + 1));
}

/**
 * palindrome_helper - helper function
 * @s: string to check
 * @start: start index
 * @end: end index
 *
 * Return: 1 if palindrome, 0 if not
 */
int palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if string is palindrome, 0 if not
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	int len = str_len(s);

	if (len <= 1)
		return (1);
	return (palindrome_helper(s, 0, len - 1));
}
