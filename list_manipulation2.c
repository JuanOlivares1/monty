#include "monty.h"

/**
 * pall - prints all stack
 * @stack: top
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *top = *stack;

	printf("%d\n", top->n);
}
