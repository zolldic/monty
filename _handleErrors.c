#include "monty.h"

/**
 * _error - function that handle errors
 * @object: characteristics of the file.
 */

void _error(obj_t *object)
{

	/**
	 * 0 - ac != 2 condation
	 * 1 - if opening file failed.
	 * 2 - invalid instructions
	 */

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
			fprintf(stderr, "L%u: unknown instruction %s\n", object->line,
								object->str_tokenized[0]);
			break;
		case PUSHERR:
			/* error with a push command */
			fprintf(stderr, "L%u: usage: push integer\n", object->line);
			break;
		default:
			_error2(object);
			break;
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
			fprintf(stderr, "L%u: can't pint, stack empty\n", object->line);
			break;
		case POPERR:
			fprintf(stderr, "L%u: can't pop an empty stack\n", object->line);
			break;
		case SWAPERR:
			fprintf(stderr, "L%u: can't swap, stack too short\n", object->line);
			break;
		case ADDERR:
			fprintf(stderr, "L%u: can't add, stack too short\n", object->line);
			break;
		case SUBERR:
			fprintf(stderr, "L%u: can't sub, stack too short\n", object->line);
			break;
		case DIVERR:
			fprintf(stderr, "L%u: can't div, stack too short\n", object->line);
			break;
		case ZERODIV:
			fprintf(stderr, "L%u: division by zero\n", object->line);
			break;
		case MULERR:
			fprintf(stderr, "L%u: can't mul, stack too short\n", object->line);
			break;
		case MODERR:
			fprintf(stderr, "L%u: can't mod, stack too short\n", object->line);
			break;
		case MEMERR:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}
