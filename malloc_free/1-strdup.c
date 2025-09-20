#include "main.h"

<<<<<<< HEAD
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
=======
>>>>>>> origin/main
int _strlen(char *s)
{
	int i = 0;

<<<<<<< HEAD
	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 *
 * Description: The _strdup() function returns a pointer to a new string
 * which is a duplicate of the string str. Memory for the new string is
 * obtained with malloc, and can be freed with free.
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 */
=======
	while (s[i] != '\0')
		i++;
	return (i);
}

>>>>>>> origin/main
char *_strdup(char *str)
{
	char *duplicate;
	int length, i;

	if (str == NULL)
		return (NULL);
<<<<<<< HEAD

	length = _strlen(str);

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

=======
	length = _strlen(str);
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];
>>>>>>> origin/main
	return (duplicate);
}
