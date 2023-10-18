#include "shell.h"



int _executing(char **command,char **argv, int indx)
{
	char *full_prmpt;
	pid_t a_child;
	int status;

	full_prmpt = _getpath(command[0]);
	if (!full_prmpt)
	{
		printerror(argv[0], command[0], indx);
		freearrayofdstring(command);
		return(127);
	}

	a_child = fork();
		if (a_child == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				free(full_prmpt), full_prmpt = NULL;
				freearrayofdstring(command);
			}
		}
		else
		{
			waitpid(a_child, &status, 0);
			freearrayofdstring(command);
			free(full_prmpt), full_prmpt = NULL;
		}
		return(WEXITSTATUS(status));

}

