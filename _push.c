#include "monty.h"

/**
  * add_node_end - adds a new node at the end of a stack_t list.
  * @head: stack_t list.
  * @n: new node value.
  * Return: the address of the new element, or NULL if it failed.
  */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *tail = *head;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	while (tail && tail->next)
		tail = tail->next;
	new->n = n;
	if (tail)
	{
		new->prev = tail;
		tail->next = new;
	}
	else
		*head = new;
	return (new);
}

/**
 * _push - execute push opcode
 * @st: stack
 * @object: struct contain info about data from file
 */

void _push(stack_t **st, obj_t *object)
{
	char **ob;

	ob = _tokenize(object->str, " \t\n");
	printf("ob->n = %d\n", atoi(ob[1]));
	if (_len(ob) < 2)
		object->flag = PUSHERR;
	else
		add_node_end(st, atoi(ob[1]));
}
