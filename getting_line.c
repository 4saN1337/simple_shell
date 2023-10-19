#include "shell.h"

/**
 * getting_line - Reads a line from standard input
 *
 * Return: A pointer to the string containing the line
 */
char *getting_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
