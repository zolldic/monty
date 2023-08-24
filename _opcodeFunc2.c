#include "monty.h"


/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */
void _push(stack_t **st, obj_t *object)
{
	char **ob;
	int i;

	ob = _tokenize(object->str, " \t\n");
	if (_check_push_arg(ob[1]) == -1)
	{
		object->flag = PUSHERR;
		return;
	}
	if (_len(ob) < 2)
	{
		object->flag = PUSHERR;
		i = 0;
		while (ob[i])
			free(ob[i++]);
		free(ob);
	}
	else
	{
		add_node(st, atoi(ob[1]));
		i = 0;
		while (ob[i])
			free(ob[i++]);
		free(ob);
	}
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
