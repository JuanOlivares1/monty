#include "monty.h"

/**
 * mod - finds the module of top 2 nodes
 * @stack: top
 * @ln: line number
 */
void mod(stack_t **stack, unsigned int ln)
{
	int answ, temp;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 1 || answ == 0)
		op_err(": can't mod, stack too short", ln, *stack);
	if (top->n == 0)
		op_err(": division by zero", ln, *stack);
	temp = top->n;
	pop(stack, ln);
	top = *stack;
	top->n %= temp;
}

/**
 * pchar - prints the ascii equivalent of data
 * @stack: top
 * @ln: line number
 */
void pchar(stack_t **stack, unsigned int ln)
{
	int answ;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 0)
		op_err(": can't pchar, stack empty", ln, *stack);
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", top->n);
	else
		op_err(": can't pchar, value out of range", ln, *stack);
}

/**
 * pstr - prints the ascii equivalent of data
 * @stack: top
 * @ln: line number
 */
void pstr(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *top = *stack;

	while (top != NULL)
	{
		if (top->n < 1 || top->n > 127)
			break;
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}
