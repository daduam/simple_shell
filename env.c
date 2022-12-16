#include "hsh.h"
#include "stdio.h"

/**
 * _getenv - get an environment variable.
 *
 * @name: environment variable.
 * Return: a pointer to the value in the environment, or NULL
 *         if there is no match.
 */
char *_getenv(const char *name)
{
	unsigned int n;
	char **p, *line;

	n = _strlen(name);
	p = environ;
	while (*p)
	{
		line = *p;
		if (_strncmp(name, line, n) == 1)
			return (line + n + 1);
		p++;
	}
	return (0);
}
