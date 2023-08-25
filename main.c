#include "monty.h"

/**
 * main - Entry point
 * @ac: number of command line arguments.
 * @av: comand line arguments
 * Return: 0 on Success, otherwise EXIT_FAILURE.
 */

int main(int ac, char **av)
{
	obj_t *file = malloc(sizeof(obj_t));
	stack_t *stack;

	if (!file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(file);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	if (ac != 2)
		file->flag = ACERR;
	else
	{
		file->name = av[1];
		file->str = NULL;
		file->flag = NOERR;
		file->mode = STACK;
		_readline(&stack, file);
	}

	_error(file);
	if (file->flag != NOERR)
	{
		_free_object(stack, file);
		exit(EXIT_FAILURE);
	}
	_free_object(stack, file);
	return (EXIT_SUCCESS);
}
