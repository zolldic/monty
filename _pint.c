#include "monty.h"

/**
 * _pint - execute pint opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _pint(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _pint function\n");
	object->flag = NOERR;

}
