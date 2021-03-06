#ifndef MONTY
#define MONTY

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

/* Prototypes - list manipulation*/
int isempty(stack_t **stack);
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void div2(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pstr(stack_t **stack, unsigned int ln);
void free_dlistint(stack_t *head);

/* Prototypes - file manipulation */
FILE *open_file(void);

/* Prototypes - errors */
void print_err(char *msg);
void open_f_err(char *msg);
void op_err(char *msg, int ln, stack_t *stack);
void inv_op_err(char *msg, int ln, stack_t *stack);

/* Prototypes - main */
instruction_t *c_options(instruction_t **array1);

/* Global variables */
char *file, *token;
FILE *fd;
int data;
instruction_t *array;

#endif
