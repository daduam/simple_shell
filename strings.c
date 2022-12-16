/**
 * _strlen - calculate the length of a string.
 *
 * @s: null-terminated string.
 * Return: number of bytes in the string pointed to by s.
 */
unsigned int _strlen(const char *s)
{
	unsigned int nchars;

	for (nchars = 0; s[nchars]; nchars++)
		;
	return (nchars);
}

/**
 * _strncmp - compares the first n bytes of the two strings s1 and s2.
 *
 * @s1: char*
 * @s2: char*
 * @n: number of bytes to compare.
 * Return: an integer less than, equal to, or greater than zero if s1
 *         (or the first n bytes) is found to be less than, to match,
 *         or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (1);
}
