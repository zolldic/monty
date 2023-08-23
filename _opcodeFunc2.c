#include "monty.h"

/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _push(stack_t **st, obj_t *object)
{
	char **ob;

	ob = _tokenize(object->str, " \t\n");
	if (_len(ob) < 2)
		object->flag = PUSHERR;
	else
		add_node_end(st, atoi(ob[1]));
}

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
