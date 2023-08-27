#include "monty.h"

/**
 * _nop - execute nop opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _nop(stack_t **st, obj_t *object)
{
	(void)st;
	(void)object;
}


/**
 * _pchar - print char to stdout
 * @st: stack
 * @object: struct contain info about data from file
 */

void _pchar(stack_t **st, obj_t *object)
{
	stack_t *p;

	p = *st;

	if (p == NULL)
	{
		object->flag = PEMPTYERR;
		return;
	}
	else
	{
		if (_isalpha(p->n) == 0)
		{
			printf("%c\n", p->n);
			p = p->next;
		}
		else
		{
			object->flag = PCHARERR;
			return;
		}
	}
}

/**
  * _pstr - print string.
  * @st: stack.
  * @object: struct contain info about data from file
  */
void _pstr(stack_t **st, obj_t *object)
{
	stack_t *p = *st;

	(void)object;
	while (p && p->n > 0 && p->n < 128)
	{
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @st: stack
 * @object: structure object
 */

void _rotl(stack_t **st, obj_t *object)
{
	int len;
	stack_t *top, *last;

	len = _stack_len(st);
	if (len < 2)
		return;

	top = *st;
	last = *st;
	while (last->next != NULL)
		last = last->next;

	(*st) = (*st)->next;
	last->next = top;
	top->next = NULL;
	object->flag = NOERR;
}


/**
 * _rotr - rotates the stack to the bottom
 * @st: stack
 * @object: structure object
 */

void _rotr(stack_t **st, obj_t *object)
{
	int len;
	stack_t *prelast, *last;

	len = _stack_len(st);
	if (len < 2)
		return;

	last = *st;
	prelast = last;
	while (last->next != NULL)
	{

		prelast = last;
		last = last->next;
	}

	prelast->next = NULL;
	last->prev = NULL;
	last->next = (*st);
	(*st) = last;

	object->flag = NOERR;
}
