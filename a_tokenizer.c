#include "shell.h"

/**
 * *tokenizer - the main function
 * strtok: breaks the string into words
 * @line: the input string
 * DELIMTR: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char   **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cnt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIMTR);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cnt++;
		token = strtok(NULL, DELIMTR);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (cnt + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIMTR);
	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIMTR);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
