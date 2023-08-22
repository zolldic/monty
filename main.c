#include "monty.h"

/**
 * main - Entry point
 * @ac: number of command line arguments.
 * @av: comand line arguments
 * Return: 0 on Success, otherwise EXIT_FAILURE.
 */

int main(int ac, char **av)
{
	int fd;
	obj_t *file;

	file = (obj_t *)malloc(sizeof(obj_t));
	if (!file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (ac != 2)
	{
		file->flag = 0;
		_error(file);
	}

	file->name = av[1];
	fd = open(file->name, O_RDONLY);

	if (fd == -1)
	{
		file->flag = 1;
		_error(file);
	}

	/**
	 * _readLine
	 * check if _readline return error
	 * print to stderr L<line_number>: unknown instruction <opcode>
	 */

	return (0);
}
