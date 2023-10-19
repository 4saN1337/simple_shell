#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @avariable: Name of the environment variable
 *
 * Return: The value of the environment variable as a string, or NULL
 */
char *_getenv(char *avariable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, avariable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
