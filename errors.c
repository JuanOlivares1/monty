#include "monty.h"
#include <stdlib.h>

/**
 * print_err - prints error in stderr
 * @msg: message to send
 */
void print_err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

/**
 * open_f_err - prints error in stderr
 * @msg: message to send
 */
void open_f_err(char *msg)
{
	fprintf(stderr, "%s", msg);
	fprintf(stderr, "%s\n", file);
	free(array);
	exit(EXIT_FAILURE);
}

/**
 * op_err - prints error in stderr
 * @msg: message to send
 * @ln: linenumber
 * @stack: stack
 */
void op_err(char *msg, int ln, stack_t *stack)
{
	fprintf(stderr, "L%d%s\n", ln, msg);
	free(array);
	free_dlistint(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * inv_op_err - prints error in stderr
 * @msg: message to send
 * @ln: linenumber
 * @stack: stack
 */
void inv_op_err(char *msg, int ln, stack_t *stack)
{
	fprintf(stderr, "L%d%s%s\n", ln, msg, token);
	free(array);
	free_dlistint(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
