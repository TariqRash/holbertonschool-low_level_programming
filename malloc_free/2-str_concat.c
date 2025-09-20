#include "main.h"

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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
