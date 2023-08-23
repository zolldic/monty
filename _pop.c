#include "monty.h"

/**
 * _pop - execute pop opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _pop(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _pop function\n");
	object->flag = NOERR;

}
