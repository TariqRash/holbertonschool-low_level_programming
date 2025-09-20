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
 * free_words - frees array of words
 * @words: array to free
 * @count: number of words to free
 *
 * Return: NULL
 */
char **free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
	return (NULL);
}

/**
 * fill_words - fills words array with individual words
 * @words: array to fill
 * @str: source string
 * @word_count: number of words
 *
 * Return: 0 on success, 1 on failure
 */
int fill_words(char **words, char *str, int word_count)
{
	int i = 0, j = 0, k, len, word_start;

	while (i < word_count)
	{
		while (str[j] == ' ')
			j++;
		word_start = j;
		len = word_len(str, j);
		words[i] = malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
			return (1);
		for (k = 0; k < len; k++)
			words[i][k] = str[word_start + k];
		words[i][len] = '\0';
		j += len;
		i++;
	}
	return (0);
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
	int word_count;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	if (fill_words(words, str, word_count) == 1)
		return (free_words(words, word_count));

	words[word_count] = NULL;
	return (words);
}
