#include "shell.h"

/**
 * main - main file of the simple shell
 * @ac: Arguments numbers
 * @argv: The arguments
 * Return: 0 Always (success).
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, indx = 0;
	(void) ac;
	while (1)
	{
		line = getting_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		indx++;
		command = tokenizer(line);
		if (!command)
			continue;
		status = _executing(command, argv, indx);
	}
}
