#include "monty.h"

/**
 * main - Entry point
 * @ac: number of command line arguments.
 * @av: comand line arguments
 * Return: 0 on Success, otherwise EXIT_FAILURE.
 */

int main(int ac, char **av)
{
	int n;
	obj_t *file;

	file = (obj_t *)malloc(sizeof(obj_t));
	if (!file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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

	_readline(file);
	_error(file);

	return (0);
}
