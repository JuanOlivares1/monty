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
	int  i, ln = 0, f = 1;
	char str[320];
	stack_t *stack = NULL;

	if (ac != 2)
		print_err("USAGE: monty file");
	file = av[1];
	fd = open_file();
	array = c_options(&array);
	while (fgets(str, 320, fd) != NULL)
	{
		ln++;
		token = strtok(str, "\n\t ");
		if (token == NULL || token[0] == '#')
			continue;
		for (i = 0; i < 13; i++)
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
	}
	fclose(fd);
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

	array = malloc(sizeof(instruction_t) * 14);
	if (array == NULL)
		print_err("Error: malloc failed");
	array[0].opcode = "push";
	array[0].f = &push;
	array[1].opcode = "pall";
	array[1].f = &pall;
	array[2].opcode = "pint";
	array[2].f = &pint;
	array[3].opcode = "pop";
	array[3].f = &pop;
	array[4].opcode = "swap";
	array[4].f = &swap;
	array[5].opcode = "add";
	array[5].f = &add;
	array[6].opcode = "nop";
	array[6].f = &nop;
	array[7].opcode = "sub";
	array[7].f = &sub;
	array[8].opcode = "div";
	array[8].f = &div2;
	array[9].opcode = "mul";
	array[9].f = &mul;
	array[10].opcode = "mod";
	array[10].f = &mod;
	array[11].opcode = "pchar";
	array[11].f = &pchar;
	array[12].opcode = "pstr";
	array[12].f = &pstr;
	return (array);
}
