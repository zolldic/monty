#include "monty.h"

/**
  * _readline - read a file line by line.
  * @file: object to store data.
  * Return: 0 (SUCCESS) -1 otherwise.
  */
int _readline(obj_t *file)
{
	FILE *fp;
	int len = 0;
	ssize_t read;

	fp = fopen(file->name, "r");
	if (fp == NULL)
	{
		file->flag = FAERR;
		return (-1);
	}
	while ((read = getline(&(file->str), &len, fp)) != -1)
	{
		if (!_exec(file))
		{
			/* flag = {LIERR | UKERR} */
			break;
		}
	}

	fclose(fp);
	return (0);
}

/**
  * _exec - handle the execution process of opcode.
  * @object: object holding opcode data.
  * Return: 0 (SUCCESS) -1 otherwise.
  */
int _exec(obj_t *object)
{
	int i;
	char *str;
	instruction_t s[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{NULL, NULL}
		};

	str = strtok(object->str, " \t\n");
	for (i = 0; s[i].opcode; i++)
		if (strcmp(s[i].opcode, str))
			return (s[i].f(&stack, object));
	/* unknown instruction */
	object->flag = UKERR;
	return (-1);
}
