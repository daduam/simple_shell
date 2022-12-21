#include "stdio.h"

#include "hsh.h"

/**
 * _perror - print error.
 */
void _perror(void)
{
	char *exec_name = _getenv("_");

	perror(exec_name);
}
