#ifndef HSH_H
#define HSH_H

#define PROMPT "#cisfun$ "

extern char **environ;

char *_getenv(const char *name);
unsigned int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, unsigned int n);

int read_cmd(char **cmd);
int handle_cmd(char *cmd);

void _perror(void);

void render_prompt(void);
void handle_eof(void);

#endif
