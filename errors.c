#include "monty.h"

/**
 * print_err - prints error in stderr
 * @msg: message to send
 */
void print_err(char *msg)
{
	write(2, msg, strlen(msg));
	exit(EXIT_FAILURE);
}

/**
 * open_f_err - prints error in stderr
 * @msg: message to send
 */
void open_f_err(char *msg)
{
	write(2, msg, strlen(msg));
	write(2, file, strlen(file));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * push_err - prints error in stderr
 * @msj: message to send
 * @ln: linenumber
 * @stack: stack
 */
void push_err(char *msg, int ln, stack_t *stack)
{
	fprintf(stderr, "L%d", ln);
	fprintf(stderr, "%s\n", msg);
	free(array);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
