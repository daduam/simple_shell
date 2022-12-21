#include "sys/types.h"
#include "sys/wait.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

#include "hsh.h"

/**
 * read_cmd - read command from stdin.
 *
 * @cmd: command
 * Return:  1 on success. -1 on failure.
 */
int read_cmd(char **cmd)
{
	int nbytes;
	char ch, *p;

	p = *cmd;
	while (1)
	{
		nbytes = read(STDIN_FILENO, &ch, 1);
		if (nbytes == -1)
		{
			_perror();
			exit(1);
		}
		if (nbytes == 0)
			return (-1);
		if (ch == '\n')
		{
			*p = '\0';
			return (1);
		}
		*p++ = ch;
	}
}

/**
 * handle_cmd - handle command
 *
 * @cmd: command
 * Return: 1 on success. -1 on failure.
 */
int handle_cmd(char *cmd)
{
	int wstatus;
	pid_t cpid;
	char *nargv[] = {NULL, NULL};

	cpid = fork();
	if (cpid == -1)
	{
		_perror();
		return (-1);
	}
	if (cpid == 0)
	{
		nargv[0] = cmd;
		if (execve(cmd, nargv, environ) == -1)
			return (-1);
	}
	else
	{
		if (waitpid(cpid, &wstatus, WUNTRACED) == -1)
		{
			_perror();
			exit(1);
		}
	}
	return (1);
}
