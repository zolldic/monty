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
#define PUSHERR 4
#define PINTERR 5
#define POPERR 6
#define SWAPERR 7
#define ADDERR 8
#define MEMERR 9
#define SUBERR 10

#define DIVERR 11
#define ZERODIV 12

#define MULERR 13
#define MODERR 14

#define PCHARERR 15
#define PEMPTYERR 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



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
 * struct obj - structre to contain the information about opcodes.
 * @name: file name.
 * @str: the opcode name.
 * @line: the line of the opcode in the file.
 * @mode: controller to switch moods (STACK, QUEUE)
 * @flag: an integer value to controle errors messages.
 * @str_tokenized: refernce to str tokenized array.
 */

typedef struct obj
{
	char *name;
	char *str;
	unsigned int line;
	int mode;
	int flag;
	char **str_tokenized;
} obj_t;

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
int _readline(stack_t **, obj_t *);
int _exec(stack_t **, obj_t *object);
void _error(obj_t *);
void _error2(obj_t *);

void _free_object(stack_t *s, obj_t *object);
char **_tokenize(char *str, char *split);
int _len(char **o);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void _free_stack(stack_t *head);
int _stack_len(stack_t **st);
int _empty(char *token);
int _isnumber(char *d);
int _isalpha(char c);

/* opcodes functions */
void _push(stack_t **, obj_t *);
void _pall(stack_t **, obj_t *);
void _pint(stack_t **, obj_t *);
void _pop(stack_t **, obj_t *);
void _swap(stack_t **, obj_t *);
void _add(stack_t **, obj_t *);
void _nop(stack_t **, obj_t *);
void _sub(stack_t **st, obj_t *object);
void _div(stack_t **st, obj_t *object);
void _mul(stack_t **st, obj_t *object);
void _mod(stack_t **st, obj_t *object);
void _pchar(stack_t **st, obj_t *object);

#endif
