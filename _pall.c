#include "monty.h"

/**
 * _pall - execute pall opcode
 * @st: stack
 * @object: struct contain info about data from file
 */


void _pall(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;

	printf("this is _pall function\n");
	object->flag = NOERR;

}
