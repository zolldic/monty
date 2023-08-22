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
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", object->name);
			break;
		case 2:
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>");
		default:
			break;
	}

	exit(EXIT_FAILURE);
}
