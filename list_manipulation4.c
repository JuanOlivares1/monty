#include "monty.h"

/**
 * mod - divides top 2 nodes
 * @stack: top
 * @ln: line number
 */
void mod(stack_t **stack, unsigned int ln)
{
	int answ, temp;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 1 || answ == 0)
		op_err(": can't div, stack too short", ln, *stack);
	if (top->n == 0)
		op_err(": division by zero", ln, *stack);
	temp = top->n;
        pop(stack, ln);
        top = *stack;
        top->n %= temp;
}
