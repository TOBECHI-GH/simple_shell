#include "holberton.h"

/**
* envFunc - prints the environment
* @build: input build
* Return: Always 1
*/
int envFunc(config *build)
{
    printList(build->env);
    return (1);
}

/**
* setenvFunc - adds env variable if it does not exist;
* modify env variable if it does
* @build: input build
* Return: Always 1
*/
int setenvFunc(config *build)
{
    register int index, len;
    static char _buffer[BUFSIZE];

    if (countArgs(build->args) != 3)
    {
        errno = EWSIZE;
        errorHandler(build);
        return (1);
    }
    len = _strlen(build->args[1]) + _strlen(build->args[2]) + 2;
    _strcat(_buffer, build->args[1]);
    _strcat(_buffer, "=");
    _strcat(_buffer, build->args[2]);
    insertNullByte(_buffer, len - 1);
    index = searchNode(build->env, build->args[1]);
    if (index == -1)
    {
        addNodeEnd(&build->env, _buffer);
        insertNullByte(_buffer, 0);
        return (1);
    }
    deleteNodeAtIndex(&build->env, index);
    addNodeAtIndex(&build->env, index, _buffer);
    insertNullByte(_buffer, 0);
    return (1);
}

/**
* unsetenvFunc - deletes env variable if exists;
* will only accept valid variables names
* @build: input build
* Return: Always 1
*/
int unsetenvFunc(config *build)
{
    register int found_Var, i = 1;
    _Bool found_Match = false;

    while (build->args[i])
    {
        if (_isalpha(build->args[i][0]) || build->args[i][0] == '_')
        {
            found_Var = searchNode(build->env, build->args[i]);
            if (found_Var > -1)
            {
            deleteNodeAtIndex(&build->env, found_Var);
            found_Match = true;
            }
        }
        i++;
    }
    if (found_Match == false)
    {
        errno = ENOSTRING;
        errorHandler(build);
    }
    return (1);
}

/**
* _isalpha - checks if c is an alphabetic character
* @c: potential alphabetical value
* Return: if c is a letter, returns 1. Otherwise, return 0.
*/
int _isalpha(int c)
{
    if (c > 64 && c < 91)
        return (1);
    else if (c > 96 && c < 123)
        return (1);
    else
        return (0);
}
