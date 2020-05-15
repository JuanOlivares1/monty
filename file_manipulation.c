#include "monty.h"

/**
 * open_file - open a file
 *
 * Return: fd of opened file or error
 */
FILE *open_file(void)
{
	fd = fopen(file, "r");
	if (fd == NULL)
		open_f_err("Error: Can't open file ");
	return (fd);
}
