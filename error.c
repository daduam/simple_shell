#include "stdio.h"

#include "hsh.h"

/**
 * _perror - print error.
 */
void _perror(void)
{
	char *exec_name = "./shell";

	perror(exec_name);
}
