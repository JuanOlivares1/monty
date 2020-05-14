#include "monty.h"

/**
 * main - main function
 * @ac: args count
 * @av: args values
 *
 * Return: 0 succes, -1 error
 */
int main(int ac, char **av)
{
	int fd, i, ln = 0, f = 1;
	char *content;
	stack_t *stack = NULL;

	if (ac != 2)
		print_err("USAGE: monty <file>\n");
	file = av[1];
	fd = open_file();
	content = read_file(fd);
	close(fd);
	array = c_options(&array);
	token = strtok(content, "\n\t ");
	while (token != NULL)
	{
		ln++;
		cpy = strdup(token);
		if (cpy == NULL)
			print_err("Error: malloc failed");
		for (i = 0; i < 2; i++)
		{
			f = 1;
			if (strcmp(array[i].opcode, token) == 0)
			{
				array[i].f(&stack, ln);
				f = 0;
				break;
			}
		}
		if (f == 1)
			inv_op_err(": unknown instruction ", ln, stack);
		token = strtok(NULL, "\n\t ");
		free(cpy);
	}
	free(array);
	free_dlistint(stack);
	return (0);
}

/**
 * c_options - main function
 * @array1: array
 *
 * Return: array
 */
instruction_t *c_options(instruction_t **array1)
{
	instruction_t *array = *array1;

	array = malloc(sizeof(instruction_t) * 3);
	if (array == NULL)
		print_err("Error: malloc failed");
	array[0].opcode = "push";
	array[0].f = &push;
	array[1].opcode = "pall";
	array[1].f = &pall;
	return (array);
}
