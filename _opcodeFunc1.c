#include "monty.h"

/**
 * _add - execute add opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _add(stack_t **st, obj_t *object)
{
	stack_t *new;

	new = *st;
	new->n += (*st)->next->n;
	new->next = new->next->next;

	object->flag = NOERR;
}

/**
 * _nop - execute nop opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _nop(stack_t **st, obj_t *object)
{
	(void)st;

	object->flag = NOERR;
}

/**
 * _pall - execute pall opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _pall(stack_t **st, obj_t *object)
{
	stack_t *p = *st;

	if (object->mode == STACK)
	{
		while (p)
		{
			printf("%d\n", p->n);
			fflush(stdout);
			p = p->next;
		}
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

	p = *st;

	if (object->mode == STACK)
	{
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
	object->flag = NOERR;

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

	if (object->mode == STACK)
	{
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

	object->flag = NOERR;

}
