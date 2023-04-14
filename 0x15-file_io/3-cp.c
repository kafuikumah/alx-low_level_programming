#include "main.h"

void free_close(char **buf, int *fd1, int *fd2);

/**
* main - a program that copies the content of a file to anothe file
* @argc: the number of cmd-line arguments
* @argv: argv[1] (source file), argv[2] (destination file)
* Return: returns (0) success, exits on error
*/
int main(int argc, char *argv[])
{
	int i = 0;
	int n, n1, fd_from, fd_to, *fd1_ptr = &fd_from, *fd2_ptr = &fd_to;
	char *buf, **buf_ptr = &buf;

	if (argc != 3)
	{
		/* Print error message if incorrect number of arguments provided */
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		/* Print error message if unable to read source file */
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open the destination file */
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		/* Print error message if unable to write to destination file */
		dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
		exit(99);
	}

	/* Allocate memory for buffer */
	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (-1);

	do {
		/* Read from source file */
		n = read(fd_from, buf, 1024);
		if (n == -1)
		{
			/* Print error message if unable to read from source file */
			dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
			exit(98);
		}

		/* Write to destination file */
		n1 = write(fd_to, buf, n);
		if (n1 != n)
		{
			/* Print error message if unable to write to destination file */
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
			exit(99);
		}

		i++;
	} while (n == 1024);

	/* Free memory and close files */
	free_close(buf_ptr, fd1_ptr, fd2_ptr);

	return (0);
}

/**
* free_close - free malloc'd memory and closes opened files
* @buf: pointer to the string buf
* @fd1: pointer to the fd_from
* @fd2: pointer to fd_to
* Return: returns nothing
*/
void free_close(char **buf, int *fd1, int *fd2)
{
	int n, n1;

	/* Free memory allocated for buffer */
	free(*buf);

	/* Close the source file */
	n = close(*fd1);
	if (n == -1)
	{
		/* Print error message if unable to close source file */
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", *fd1);
		exit(100);
	}

	/* Close the destination file */
	n1 = close(*fd2);
	if (n1 == -1) 
	{
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", *fd2);
		exit(100);
	}
}
