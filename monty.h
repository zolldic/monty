#ifndef MONTY_H
#define MONTY_H

/* different libs used throughout the source code */

#define _GNU_SOURCE
#define STACK 0
#define QUEUE 1
#define NOERR -1
#define ACERR 0
#define FAERR 1
#define UKERR 2
#define LIERR 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


/**
 * struct obj - structre to contain the information about opcodes.
 * @name: file name.
 * @str: the opcode name.
 * @line: the line of the opcode in the file.
 * @mode: controller to switch moods (STACK, QUEUE)
 * @flag: an integer value to controle errors messages.
 */

typedef struct obj
{
	char *name;
	char *str;
	unsigned int line;
	int mode;
	int flag;
} obj_t;

/*
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
	void (*f)(stack_t **stack, obj_t *);
} instruction_t;



/* functions */
int _readline(obj_t *);
int _exec(obj_t *object);
void _error(obj_t *);
void _free_object(obj_t *);

/* opcodes functions */
void _push(stack_t **, obj_t *);
void _pall(stack_t **, obj_t *);
void _pint(stack_t **, obj_t *);
void _pop(stack_t **, obj_t *);
void _swap(stack_t **, obj_t *);
void _add(stack_t **, obj_t *);
void _nop(stack_t **, obj_t *);

extern stack_t *stack;
#endif
