#include "monty.h"

/**
 * _tokenize - function that split a string into tokens, our own (strtok).
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */

char **_tokenize(char *str, char *split)
{
	char **toks;
	int delim = 0;
	int i, index = 0;
	int start, end;

	if (!str || !split)
		return (NULL);
	for (i = 0; str[i]; i++)
		if (strchr(split, str[i]) != NULL)
			delim++;
	toks = (char **)malloc(sizeof(char *) * (delim + 2));
	if (!toks)
	{
		perror("malloc");
		return (NULL);
	}

	start = 0;
	while (str[start] != '\0')
	{
		while (str[start] != '\0' && strchr(split, str[start]) != NULL)
			start++;
		if (str[start] == '\0')
			break;

		end = start;
		while (str[end] != '\0' && strchr(split, str[end]) == NULL)
			end++;

		toks[index] = malloc(end - start + 1);
		strncpy(toks[index], str + start, end - start);
		toks[index][end - start] = '\0';
		index++;
		start = end;
	}

	toks[index] = NULL;

	return (toks);
}
