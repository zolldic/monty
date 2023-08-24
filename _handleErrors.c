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
  * _free_object - free object.
  * @object: object to free.
  */
void _free_object(obj_t *object)
{
	int i;
	/*
	   * to be free`d
	   * str, str_tokenized, ref_to_stack.
	   *
	*/
	if (object->str)
		free(object->str);
	i = 0;
	if (object->str_tokenized)
	{
		while (object->str_tokenized[i])
			free(object->str_tokenized[i++]);
		free(object->str_tokenized);
	}
	if (object->ref_to_stack)
		_free_stack(object->ref_to_stack);
	free(object);
}
