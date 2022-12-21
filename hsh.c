#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

#include "hsh.h"

/**
 * main - hsh shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *cmd = malloc(1024);

	while (1)
	{
		render_prompt();
		if (read_cmd(&cmd) == -1)
		{
			handle_eof();
			break;
		}
		if (handle_cmd(cmd) == -1)
		{
			_perror();
			break;
		}
	}
	free(cmd);
	return (0);
}
