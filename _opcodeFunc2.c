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
	else
	{
		new = *st;
		res = (*st)->next->n + (*st)->n;
		new->n = res;
		new->next = new->next->next;
		object->flag = NOERR;
	}
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
	else
	{
		new = *st;
		res = (*st)->next->n - (*st)->n;
		new->n = res;
		new->next = new->next->next;
		object->flag = NOERR;
	}
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
	else
	{
		new = *st;
		if (new->n == 0)
		{
			object->flag = ZERODIV;
			return;
		}
		res = (*st)->next->n / (*st)->n;
		new->n = res;
		new->next = new->next->next;
		object->flag = NOERR;
	}

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
	else
	{
		new = *st;
		res = (*st)->next->n * (*st)->n;
		new->n = res;
		new->next = new->next->next;
		object->flag = NOERR;
	}
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
		object->flag = DIVERR;
		return;
	}
	else
	{
		new = *st;
		if (new->n == 0)
		{
			object->flag = ZERODIV;
			return;
		}
		res = (*st)->next->n % (*st)->n;
		new->n = res;
		new->next = new->next->next;
		object->flag = NOERR;
	}
}
