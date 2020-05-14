#include "monty.h"

/**
 * pint - prints top
 * @stack: top
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	int answ;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 0)
		push_err(": can't pint, stack empty", ln, top);
	printf("%d\n", top->n);
}
