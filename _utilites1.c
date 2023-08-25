#include "monty.h"

/**
  * _empty - check if string is empty.
  * @token: string to check.
  * Return: 1 if string is empty 0 otherwise.
  */
int _empty(char *token)
{
	int i;

	for (i = 0; token[i]; i++)
		if (token[i] != ' ' && token[i] != '\n' && token[i] != '\t')
			return (0);
	return (1);
}

/**
  * _isnumber - check if string is number.
  * @d: number.
  * Return: 1 if is number and 0 if it's not.
  */
int _isnumber(char *d)
{
	int n;

	if (!d)
		return (0);
	if (d[0] == '-')
		n = 1;
	else
		n = 0;

	while (d[n])
		if (!isdigit(d[n++]))
			return (0);
	return (1);
}

#include "monty.h"

/**
 * _stack_len - function to get stack length;
 * @st: stack
 * Return: stack length
 */

int _stack_len(stack_t **st)
{
	int i;
	stack_t *p;

	p = *st;
	i = 0;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}
