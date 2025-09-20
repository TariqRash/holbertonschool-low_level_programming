#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @str: string to analyze
 *
 * Return: number of words
 */
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

/**
 * word_len - gets the length of a word
 * @str: string
 * @start: starting position
 *
 * Return: length of word
 */
int word_len(char *str, int start)
{
	int len = 0;

	while (str[start + len] && str[start + len] != ' ')
		len++;
	return (len);
}

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
char **strtow(char *str)
{
	char **words;
	int i, j, k, word_count, len, word_start;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (str[j] == ' ')
			j++;

		word_start = j;
		len = word_len(str, j);

		words[i] = malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (k = 0; k < len; k++)
			words[i][k] = str[word_start + k];
		words[i][len] = '\0';

		j += len;
		i++;
	}

	words[i] = NULL;
	return (words);
}
