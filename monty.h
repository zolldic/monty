#ifndef MONTY_H
#define MONTY_H

/* different libs used throughout the source code */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct obj - structre to contain the information about opcodes.
 * @str: the opcode name.
 * @line: the line of the opcode in the file.
 * @mode: controller to switch moods (STACK, QUEUE)
 * @flag: an integer value to controle errors messages.
 */

typedef struct obj
{
	char *name;
	int line;
	int mode;
	int flag;
} obj_t; 

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions */

void _error(obj_t *);
#endif
