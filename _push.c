#include "monty.h"

/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _push(stack_t **st, obj_t *object)
{
	char **ob;
	stack_t *tmp;

	ob = malloc(sizeof(char **));
	if (!ob)
		fprintf(stderr, "Error: malloc failed");

	ob = _tokenize(object->str, " \t");

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
		fprintf(stderr, "Error: malloc failed");

	tmp->n = atoi(ob[1]);

	if ((*st) == NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		(*st) = tmp;
	}
	else
	{
		(*st)->next = tmp;
		tmp->prev = (*st);
		(*st) = tmp;
	}

	object->flag = NOERR;

}
