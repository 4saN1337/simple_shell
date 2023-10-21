#include "shell.h"

/**
 * freearrayofdstrin - Short description, single line
 * @arr: Description of parameter arr
 *
 * Description: Longer description of the function
 */
void freearrayofdstring(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;

	free(arr), arr = NULL;
}

/**
 * printerror - Short description, single line
 * @name: Description of parameter name
 * @cmd: Description of parameter cmd
 * @indx: Description of parameter indx
 *
 * Description: Longer description of the function
 */
void printerror(char *name, char *cmd, int indx)
{
	char *index, ermssg[] = ": not found\n";

	index = _itoa(indx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ermssg, _strlen(ermssg));

	free(index);
}

/**
 * _itoa - Short description, single line
 * @n: Description of parameter n
 *
 * Description: Longer description of the function
 *
 * Return: Description of the returned value
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverse_string - Reverses a string
 * @str: Pointer to the string to be reversed
 * @len: Length of the string
 *
 * Description: This function reverses the string pointed to by `str` in place.
 *
 * Return: None
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
