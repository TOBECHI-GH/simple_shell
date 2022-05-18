#include "holberton.h"

/**
* checkPath - this searches $PATH for directory of command
* @build: the input build
*/
_Bool checkPath(config *build)
{
register int len_;
static char buffer_[BUFSIZE];
struct stat st;
char *tok, *copy, *delim = ":", *tmp;
_Bool inLoop = false;

if (checkEdgeCases(build))
return (true);
copy = _strdup(build->path);
tok = _strtok(copy, delim);
while (tok)
{
tmp = inLoop ? tok - 2 : tok;
if (*tmp == 0 && stat(build->args[0], &st) == 0)
{
build->fullPath = build->args[0];
free(copy);
return (true);
}
len_ = _strlen(tok) + _strlen(build->args[0]) + 2;
_strcat(buffer_, tok);
_strcat(buffer_, "/");
_strcat(buffer_, build->args[0]);
insertNullByte(buffer_, len - 1);
if (stat(buffer_, &st) == 0)
{
free(copy);
build->fullPath = buffer_;
return (true);
}
insertNullByte(buffer_, 0);
tok = _strtok(NULL, delim);
inLoop = true;
}
build->fullPath = build->args[0];
free(copy);
return (false);
}

/**
* checkEdgeCases - helper func for check path to check edge cases
* @build: input build
* Return: returns true if found, false if not
*/
_Bool checkEdgeCases(config *build)
{
char *copy_;
struct stat st;

copy_ = _strdup(build->path);
if (!copy_)
{
build->fullPath = build->args[0];
free(copy_);
return (true);
}
if (*copy_ == ':' && stat(build->args[0], &st) == 0)
{
build->fullPath = build->args[0];
free(copy_);
return (true);
}
free(copy_);
return (false);
}
