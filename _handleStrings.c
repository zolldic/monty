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
		file->flag = 1;
		return (-1);
	}
	while ((read = getline(&(file->str), &len, fp)) != -1)
	{
		if (!exec(file))
		{
			file->flag = LIERR;
			break;
		}
	}

	fclose(fp);
	return (0);
}
