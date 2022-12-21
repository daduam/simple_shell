#include "unistd.h"

#include "hsh.h"

/**
 * render_prompt - render shell prompt in interactive-mode.
 */
void render_prompt(void)
{
	if (isatty(STDIN_FILENO))
		if (write(STDIN_FILENO, PROMPT, sizeof(PROMPT)) == -1)
			_perror();
}

/**
 * handle_eof - handle EOF in interactive-mode.
 */
void handle_eof(void)
{
	if (isatty(STDIN_FILENO))
		if (write(STDIN_FILENO, "\n", 1))
			_perror();
}
