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
	stack_t *stack = malloc(sizeof(stack_t));

	if (!file || !stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (stack)
			free(stack);
		if (file)
			free(file);
		exit(EXIT_FAILURE);
	}

	file->ref_to_stack = stack;
	if (ac != 2)
	{
		file->flag = ACERR;
		/*
		 * be careful when calling this function.
		 * add _free_object() function to call it inside this function.
		 */
		_error(file);
	}

	file->name = av[1];
	file->str = NULL;
	file->flag = NOERR;
	file->mode = STACK;

	_readline(&stack, file);
	_error(file);
	_free_object(file);

	return (0);
}
