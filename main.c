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
	int fd, i, ln = 0;
	char *content;
	stack_t *stack = NULL;

	if (ac != 2)
		print_err("USAGE: monty <file>\n");
	file = av[1];
	fd = open_file();
	content = read_file(fd);
	close(fd);
	array = c_options(&array);
	token = strtok(content,"\n\t ");
	while (token != NULL)
	{
		ln++;
		for (i = 0; array; i++)
		{
			if (strcmp(array[i].opcode, token) == 0)
			{
				array[i].f(&stack, ln);
				break;
			}
		}
		token = strtok(NULL, "\n\t ");
	}
	free(array);
	free_dlistint(stack);
	return (0);
}

/**
 * options - main function
 * @array: array
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
