#include "monty.h"

/**
  * _stack - change the mode to stack.
  * @st: stack.
  * @object: object that store data.
  */
void _stack(stack_t **st, obj_t *object)
{
	(void)st;

	object->mode = STACK;
}

/**
  * _queue - change the mode to queue.
  * @st: stack.
  * @object: object that store data.
  */
void _queue(stack_t **st, obj_t *object)
{
	(void)st;

	object->mode = QUEUE;
}
