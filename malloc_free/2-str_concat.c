#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: The returned pointer should point to a newly allocated
 * space in memory which contains the contents of s1, followed by the
 * contents of s2, and null terminated. If NULL is passed, treat it as
 * an empty string.
 *
 * Return: pointer to newly allocated space with concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	int len1, len2, i, j;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < len2; j++)
		result[i + j] = s2[j];

	result[i + j] = '\0';

	return (result);
}
