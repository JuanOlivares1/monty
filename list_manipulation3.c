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
 * sub - adds top 2 nodes
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

/**
 * div2 - divides top 2 nodes
 * @stack: top
 * @ln: line number
 */
void div2(stack_t **stack, unsigned int ln)
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
        top->n /= temp;
}
