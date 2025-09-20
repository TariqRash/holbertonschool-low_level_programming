#include "main.h"

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

int word_len(char *str, int start)
{
	int len = 0;

	while (str[start + len] && str[start + len] != ' ')
		len++;
	return (len);
}

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
