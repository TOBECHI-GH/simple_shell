#include "holberton.h"

/**
 * _getenv - it retrieves env variable that matches input string
 * @input: the input string
 * @environ: thelocal environmental variables
 * Return: the string of env variable
 */
char *_getenv(char *input, char **environ)
{
	register int j = 0;
	char *tok, *right_;

	while (environ[j])
	{
		tok = _strtok(environ[j], "=");
		if (_strcmp(tok_, input) == 0)
		{
			right_ = _strtok(NULL, "=");
			return (right_);
		}
		j++;
	}
	return (NULL);
}