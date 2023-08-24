#include "monty.h"

/**
 * _error2 - function that handle errors
 * @object: characteristics of the file.
 */

void _error2(obj_t *object)
{

	switch (object->flag)
	{
		case PINTERR:
			fprintf(stderr, "L%d: can't pint, stack empty\n", object->line);
			break;
		case POPERR:
			fprintf(stderr, "L%d: can't pop an empty stack\n", object->line);
			break;
		case SWAPERR:
			fprintf(stderr, "L%d: can't swap, stack too short\n", object->line);
			break;
		case ADDERR:
			fprintf(stderr, "L%d: can't add, stack too short\n", object->line);
			break;
		default:
			/* NOERR */
			break;
	}

	if (object->flag != NOERR)
	{
		_free_object(object);
		exit(EXIT_FAILURE);
	}
}



