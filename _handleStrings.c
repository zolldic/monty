#include "monty.h"

/**
  * _readline - read a file line by line.
  * @file: object to store data.
  * @stack: stack ds.
  * Return: 0 (SUCCESS) -1 otherwise.
  */
int _readline(stack_t **stack, obj_t *file)
{
	FILE *fp;
	size_t len = 0;
	ssize_t read;

	fp = fopen(file->name, "r");
	if (fp == NULL)
	{
		file->flag = FAERR;
		return (-1);
	}


	file->line = 0;
	while ((read = getline(&(file->str), &len, fp)) != -1)
	{
		(file->line)++;
		if (_exec(stack, file) || file->flag != -1)
			/*flag = {LIERR | UKERR} */
			continue;
		else
			break;

	}

	fclose(fp);
	return (0);
}

/**
  * _exec - handle the execution process of opcode.
  * @object: object holding opcode data.
  * @stack: stack ds.
  * Return: 0 (SUCCESS) -1 otherwise.
  */
int _exec(stack_t **stack, obj_t *object)
{
	int i;
	char **str;

	instruction_t s[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{"swap", _swap},
			{"add", _add},
			{"nop", _nop},
			{NULL, NULL}
		};

	str = _tokenize(object->str, " \t\n");
	if (str == NULL)
	{
		object->flag = PUSHERR;
		return (-1);
	}
	for (i = 0; s[i].opcode; i++)
	{
		if (strcmp(s[i].opcode, str[0]) == 0)
		{
			s[i].f(stack, object);
			break;
		}
	}

	/* if the file empty */
	/* unknown instruction */
	/* free the stack */
	return (-1);
}
