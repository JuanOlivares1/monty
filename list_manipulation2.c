#include "monty.h"

/**
 * pint - prints top
 * @stack: top
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln)
{
	int answ;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 0)
		push_err(": can't pint, stack empty", ln, top);
	printf("%d\n", top->n);
}

/**
 * pop - removes top node
 * @stack: top
 * @ln: line number
 */
void pop(stack_t **stack, unsigned int ln)
{
	int answ;
	stack_t *old;

	answ = isempty(stack);
	if (answ == 0)
		push_err(": can't pop an empty stack", ln, *stack);
	else if (answ == 1)
	{
		free(*stack);
		*stack = NULL;
	} else
	{
		old = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(old);
	}
}
