#include "monty.h"

/**
 * _nop - execute nop opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _nop(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _nop function\n");
	object->flag = NOERR;

}
