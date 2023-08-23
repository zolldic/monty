#include "monty.h"

/**
 * _add - execute add opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _add(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _add function\n");
	object->flag = NOERR;

}
