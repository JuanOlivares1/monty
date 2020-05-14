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

/**
 * swap - swaps top 2 nodes
 * @stack: top
 * @ln: line number
 */
void swap(stack_t **stack, unsigned int ln)
{
	int answ;
	stack_t *temp, *second, *top = *stack;

	answ = isempty(stack);
	if (answ == 1 || answ == 0)
		push_err(": can't swap, stack too short", ln, *stack);
	second = top->next;
	temp = second->next;
	second->prev = NULL;
	second->next = top;
	top->prev = second;
	top->next = temp;
	*stack = second;
}

/**
 * add - adds top 2 nodes
 * @stack: top
 * @ln: line number
 */
void add(stack_t **stack, unsigned int ln)
{
	int answ, temp;
	stack_t *top = *stack;

	answ = isempty(stack);
	if (answ == 1 || answ == 0)
		push_err(": can't add, stack too short", ln, *stack);
	temp = top->n;
	pop(stack, ln);
	top = *stack;
	top->n += temp;
}
