#include "monty.h"


int _check_push_arg(char *c)
{
	if (*c >= 65 && *c <= 90)
		return (-1);
	if (*c >= 96 && *c <= 122)
		return (-1);

	return (0);
}

/**
  * _len - find the length of string array.
  * @o: array.
  * Return: length of string array.
  */
int _len(char **o)
{
	int i;
	unsigned int length = 0;

	for (i = 0; o[i]; i++)
		length++;
	return (length);
}

/**
  * add_node_end - adds a new node at the end of a stack_t list.
  * @head: stack_t list.
  * @n: new node value.
  * Return: the address of the new element, or NULL if it failed.
  */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *tail = *head;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	while (tail && tail->next)
		tail = tail->next;
	new->n = n;
	if (tail)
	{
		new->prev = tail;
		tail->next = new;
	}
	else
		*head = new;
	return (new);
}

/**
  * add_node - adds a new node at the beginning of a dlistint_t list.
  * @head: dlistint_t list.
  * @n: new node value.
  * Return: the address of the new element, or NULL if it failed.
  */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

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
