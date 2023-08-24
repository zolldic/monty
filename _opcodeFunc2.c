#include "monty.h"


/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _push(stack_t **st, obj_t *object)
{
	if (_len(object->str_tokenized) < 2)
		object->flag = PUSHERR;
	else
		add_node(st, atoi(object->str_tokenized[1]));
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
