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
	int i;

	fp = fopen(file->name, "r");
	if (fp == NULL)
	{
		file->flag = FAERR;
		return (-1);
	}
	while ((read = getline(&(file->str), &len, fp)) != -1)
	{
		(file->line)++;
		if (_exec(stack, file) || file->flag != -1)
			/*flag = {LIERR | UKERR} */
			break;
		i = 0;
		while ((file->str_tokenized)[i])
		{
			free((file->str_tokenized)[i]);
			i++;
		}
		free(file->str_tokenized);
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

	instruction_t s[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{"swap", _swap},
			{"add", _add},
			{"nop", _nop},
			{"sub", _sub},
			{"div", _div},
			{"mul", _mul},
			{"mod", _mod},
			{NULL, NULL}
		};

	object->str_tokenized = _tokenize(object->str, " \t\n");
	for (i = 0; s[i].opcode; i++)
	{
		if (strcmp(s[i].opcode, object->str_tokenized[0]) == 0 || 
				object->str_tokenized[0][0] == '#')
		{
			if (object->str_tokenized[0][0] != '#')
				s[i].f(stack, object);
			return (0);
		}
	}
	object->flag = UKERR;
	/* unknown instruction */
	/* free the stack */
	return (-1);
}
