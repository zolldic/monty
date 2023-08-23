#include "monty.h"

/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _push(stack_t **st, obj_t *object)
{

	char **ob;

	(void)object;
	(void)st;


	ob = malloc(sizeof(char **));
	ob = _tokenize(object->str, " \t");

	object->flag = NOERR;

}
