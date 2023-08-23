#include "monty.h"

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
		while (p && p->next)
		{
			p = p->next;
		}
		while (p)
		{
			printf("p->n = %d\n", p->n);
			printf("%d\n", p->n);
			p = p->prev;
		}
	}
}
