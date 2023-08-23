#include "monty.h"

/**
 * _swap - execute swap opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _swap(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _swap function\n");
	object->flag = NOERR;

}
