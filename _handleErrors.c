#include "monty.h"

/**
 * _error - function that handle errors
 * @object: characteristics of the file.
 */
void _error(obj_t *object)
{
	switch (object->flag)
	{
		case ACERR:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case FAERR:
			fprintf(stderr, "Error: Can't open file %s\n", object->name);
			break;
		case UKERR:
			/* unknown instruction error */
			fprintf(stderr, "L%d: unknown instruction %s", object->line, object->str);
			break;
		case LIERR:
			/* error with a command */
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
			break;
		case PUSHERR:
			/* error with a push command */
			fprintf(stderr, "L%d: usage: push integer\n", object->line);
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
		case MEMERR:
			fprintf(stderr, "Error: malloc failed\n");
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
