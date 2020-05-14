#include "monty.h"
/**
 * isempty - tells if the stack is empty
 * @stack: top
 *
 * Return: 0 is empty, -1 not empty, 1 only one node
 */
int isempty(stack_t **stack)
{
	stack_t *head = *stack;

	if (head == NULL)
		return (0);
	head = head->next;
	if (head == NULL)
		return (1);
	return (-1);
}

/**
 * push - add element to stack
 * @stack: top
 * @ln: line number
 */
void push(stack_t **stack, unsigned int ln)
{
	stack_t *new, *current = *stack;
	int empty, i = 0;

	token = strtok(NULL, "\n\t ");
	if (strcmp(token, "0") == 0)
		data = 0;
	if (strcmp(token, "0") != 0)
	{
		while (token[i] != '\0')
		{
			if ((token[i] < 48 || token[i] > 57) && token[i] != 45)
				push_err(": usage: push integer", ln, *stack);
			i++;
		}
		data = atoi(token);
		if (data == 0)
			push_err(": usage: push integer", ln, *stack);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_err("Error: malloc failed");
	new->n = data;
	empty = isempty(&current);
	if (empty == 0)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	} else
	{
		new->next = current;
		current->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints all stack
 * @stack: top
 * @ln: line number
 */
void pall(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *top = *stack;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: lisit's head
 *
 * Return: address of new node
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
