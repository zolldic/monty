#include "monty.h"


/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _push(stack_t **st, obj_t *object)
{
	stack_t *s = NULL;

	if (_len(object->str_tokenized) < 2)
		object->flag = PUSHERR;
	else
	{
		if (_isnumber(object->str_tokenized[1]))
		{
			if (object->mode == STACK)
				s = add_node(st, atoi(object->str_tokenized[1]));
			else if (object->mode == QUEUE)
				s = add_node_end(st, atoi(object->str_tokenized[1]));
			if (s == NULL)
				object->flag = MEMERR;
		}
		else
			object->flag = PUSHERR;
	}
}


/**
 * _swap - execute swap opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _swap(stack_t **st, obj_t *object)
{
	stack_t *a, *b;
	int temp;

	if (_stack_len(st) < 2)
	{
		object->flag = SWAPERR;
		return;
	}
	a = *st;
	b = (*st)->next;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * _pall - execute pall opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _pall(stack_t **st, obj_t *object)
{
	stack_t *p = *st;

	(void)object;
	while (p)
	{
		printf("%d\n", p->n);
		fflush(stdout);
		p = p->next;
	}
}

/**
 * _pint - execute pint opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _pint(stack_t **st, obj_t *object)
{
	stack_t *p;

	(void)object;
	p = *st;

	if (p == NULL)
	{
		object->flag = PINTERR;
		return;
	}
	else
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * _pop - execute pop opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _pop(stack_t **st, obj_t *object)
{
	stack_t *p;

	p = *st;

	if (p == NULL)
	{
		object->flag = POPERR;
		return;
	}
	else
	{
		(*st) = (*st)->next;
		free(p);
	}
}
