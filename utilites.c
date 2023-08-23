#include "monty.h"

/**
  * _len - find the length of string array.
  * @o: array.
  * Return: length of string array.
  */
int _len(char **o)
{
	int i;
	unsigned int length = 0;

	for (i = 0; o[i]; i++)
		length++;
	return (length);
}
