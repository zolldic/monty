#include "monty.h"

/**
 * _add - execute add opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _add(stack_t **st, obj_t *object)
{

	stack_t *new;
	int len, res;

	len = _stack_len(st);
	if (len < 2)
	{
		object->flag = ADDERR;
		return;
	}
	new = *st;
	res = (*st)->next->n + (*st)->n;
	*st = (*st)->next;
	(*st)->n = res;
	free(new);
}

/**
 * _sub - execute sub opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _sub(stack_t **st, obj_t *object)
{
	stack_t *new;
	int len, res;

	len = _stack_len(st);
	if (len < 2)
	{
		object->flag = SUBERR;
		return;
	}
	new = *st;
	res = (*st)->next->n - (*st)->n;
	*st = (*st)->next;
	(*st)->n = res;
	free(new);
}

/**
 * _div - execute div opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _div(stack_t **st, obj_t *object)
{
	stack_t *new;
	int len, res;

	len = _stack_len(st);
	if (len < 2)
	{
		object->flag = DIVERR;
		return;
	}
	new = *st;
	if (new->n == 0)
	{
		object->flag = ZERODIV;
		return;
	}
	res = (*st)->next->n / (*st)->n;
	*st = (*st)->next;
	(*st)->n = res;
	free(new);
}

/**
 * _mul - execute add opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _mul(stack_t **st, obj_t *object)
{
	stack_t *new;
	int len, res;

	len = _stack_len(st);
	if (len < 2)
	{
		object->flag = MULERR;
		return;
	}
	new = *st;
	res = (*st)->next->n * (*st)->n;
	*st = (*st)->next;
	(*st)->n = res;
	free(new);
}

/**
 * _mod - execute add opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _mod(stack_t **st, obj_t *object)
{
	stack_t *new;
	int len, res;

	len = _stack_len(st);
	if (len < 2)
	{
		object->flag = MODERR;
		return;
	}
	new = *st;
	if (new->n == 0)
	{
		object->flag = ZERODIV;
		return;
	}
	res = (*st)->next->n % (*st)->n;
	*st = (*st)->next;
	(*st)->n = res;
	free(new);
}
