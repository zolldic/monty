#include "monty.h"

/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _push(stack_t **st, obj_t *object)
{
	(void)object;
	(void)st;
	printf("this is _push function\n");
	object->flag = NOERR;

}
