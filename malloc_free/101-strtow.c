#include "main.h"

<<<<<<< HEAD
/**
 * count_words - counts the number of words in a string
 * @str: string to analyze
 *
 * Return: number of words
 */
=======
>>>>>>> origin/main
int count_words(char *str)
{
	int count = 0, i = 0, in_word = 0;

	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

<<<<<<< HEAD
/**
 * word_len - gets the length of a word
 * @str: string
 * @start: starting position
 *
 * Return: length of word
 */
=======
>>>>>>> origin/main
int word_len(char *str, int start)
{
	int len = 0;

	while (str[start + len] && str[start + len] != ' ')
		len++;
	return (len);
}

<<<<<<< HEAD
/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Description: The function returns a pointer to an array of strings (words).
 * Each element of this array should contain a single word, null-terminated.
 * The last element of the returned array should be NULL. Words are separated
 * by spaces. Returns NULL if str == NULL or str == "".
 *
 * Return: pointer to array of strings (words)
 */
=======
>>>>>>> origin/main
char **strtow(char *str)
{
	char **words;
	int i, j, k, word_count, len, word_start;

	if (str == NULL || *str == '\0')
		return (NULL);
<<<<<<< HEAD

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

=======
	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);
>>>>>>> origin/main
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (str[j] == ' ')
			j++;
<<<<<<< HEAD

		word_start = j;
		len = word_len(str, j);

=======
		word_start = j;
		len = word_len(str, j);
>>>>>>> origin/main
		words[i] = malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
<<<<<<< HEAD

		for (k = 0; k < len; k++)
			words[i][k] = str[word_start + k];
		words[i][len] = '\0';

		j += len;
		i++;
	}

=======
		for (k = 0; k < len; k++)
			words[i][k] = str[word_start + k];
		words[i][len] = '\0';
		j += len;
		i++;
	}
>>>>>>> origin/main
	words[i] = NULL;
	return (words);
}
