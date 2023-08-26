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

	if (object->mode == STACK)
	{
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
	object->flag = NOERR;
}

/**
  * _pstr - print string.
  * @st: stack.
  * @object: struct contain info about data from file
  */
void _pstr(stack_t **st, obj_t *object)
{
	stack_t *p = *st;

	if (object->mode == STACK)
	{
		while (p && p->n > 0 && p->n < 128)
		{
			printf("%c", p->n);
			p = p->next;
		}
		printf("\n");
	}
}
