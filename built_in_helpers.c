#include "holberton.h"

/**
* countArgs - this counts the number of arguments
* @args: the input array of strings
* Return: the number of strings
*/
int countArgs(char **args)
{
    register int i = 0;

    while (args[i])
        i++;
    return (i);
}

/**
* _atoi - the change string to an integer
* @s: the input string
* Return: returns -1 if it's not a valid number, else the converted number
*/
int _atoi(char *s)
{
    register int k = 0;
    unsigned long num = 0;

    while (s[k])
    {
        if (s[k] >= '0' && s[k] <= '9')
            num = num * 10 + s[k] - '0';
        else
            return (-1);
        k++;
    }
    if (num > INT_MAX)
    {
        return (-1);
    }
    return (num);
}
