#include "monty.h"

/**
 * open_file - open a file
 *
 * Return: fd of opened file or error
 */
int open_file(void)
{
	int fd_file;

	fd_file = open(file, O_RDONLY);
	if (fd_file == -1)
		open_f_err("Error: Can't open file ");
	return (fd_file);
}

/**
 * read_file - open a file
 * @fd: file descriptor of opened file
 *
 * Return: buffer with file content
 */
char *read_file(int fd)
{
	ssize_t rd;
	static char buff[1024];

	rd = read(fd, &buff, 1024);
	if (rd == -1)
		open_f_err("Error: Can't open file ");
	return (buff);
}
