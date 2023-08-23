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
		case LIERR:
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>");
		default:
			/* NOERR */
			break;
	}

	if (file->flag != NOERR)
	{
		_free_object(file);
		exit(EXIT_FAILURE);
	}
}
