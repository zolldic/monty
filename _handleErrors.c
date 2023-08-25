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
			fprintf(stderr, "L%d: unknown instruction %s", object->line,
								object->str_tokenized[0]);
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
		case SUBERR:
			fprintf(stderr, "L%d: can't sub, stack too short\n", object->line);
			break;
		case DIVERR:
			fprintf(stderr, "L%d: can't div, stack too short\n", object->line);
			break;
		case ZERODIV:
			fprintf(stderr, "L%d: division by zero\n", object->line);
			break;
		case MULERR:
			fprintf(stderr, "L%d: can't mul, stack too short\n", object->line);
			break;
		case MODERR:
			fprintf(stderr, "L%d: can't mod, stack too short\n", object->line);
			break;
		case MEMERR:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}
