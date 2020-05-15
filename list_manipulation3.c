#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: top
 * @ln: line number
 */
void nop(stack_t **stack __attribute__((unused)),
	 unsigned int ln __attribute__((unused)))
{
}

/**
 * add - adds top 2 nodes
 * @stack: top
 * @ln: line number
 */
void sub(stack_t **stack, unsigned int ln)
{
        int answ, temp;
        stack_t *top = *stack;

        answ = isempty(stack);
        if (answ == 1 || answ == 0)
                op_err(": can't sub, stack too short", ln, *stack);
        temp = top->n;
        pop(stack, ln);
        top = *stack;
        top->n -= temp;
}
