#include "shell.h"

char *_getpath(char *command)
{
	char *path_envr, *full_prmpt, *dir;
	int i;
	struct stat stt;

	for (i = 0; command[i]; i++)
	{
		if (command [i] == '/')
		{
			if (stat(command, &stt) == 0)
				return (_strdup(command));
			
			return (NULL);
		}
	}
	path_envr = _getenv("PATH");
	if (!path_envr)
		return (NULL);

	dir = strtok(path_envr, ":");
	while (dir)
	{
		full_prmpt = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_prmpt)
		{
			_strcpy(full_prmpt, dir);
			_strcat(full_prmpt, "/");
			_strcat(full_prmpt, command);
			if (stat(full_prmpt, &stt) == 0)
			{
				free(path_envr);
				return(full_prmpt);
			}
			free(full_prmpt), full_prmpt = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_envr);
	return (NULL);	
}
