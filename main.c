#include "holberton.h"

/**
* main - the entry point for application
* @ac: the argument count
* @av: the argument vector
* Return: returns 0 on success
*/
int main(int ac, char **av)
{
config build;

(void)ac;
signal(SIGINT, sigintHandler);
configInit(&build);
build.shellName = av[0];
shell(&build);
return (0);
}

/**
* configInit - this initialize member values for config struct
* @build: the input build
* Return: returns the build with initialized members
*/
config *configInit(config *build)
{
build->env = generateLinkedList(environ);
build->envList = NULL;
build->args = NULL;
build->buffer = NULL;
build->path = _getenv("PATH", environ);
build->fullPath = NULL;
build->lineCounter = 0;
build->shellName = NULL;
build->errorStatus = 0;
return (build);
}
