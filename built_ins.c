#include "holberton.h"

/**
* findBuiltIns - this validates if command is builtin and executes
* @build: the input build
* Return: returns true if found, false if not
*/
_Bool findBuiltIns(config *build)
{
    register int i = 0;
    type_b get_Built_Ins[] = {
        {"exit", exitFunc},
        {"env", envFunc},
        {"history", historyFunc},
        {"alias", aliasFunc},
        {"cd", cdFunc},
        {"setenv", setenvFunc},
        {"unsetenv", unsetenvFunc},
        {"help", helpFunc},
        {NULL, NULL}
    };

    while (get_Built_Ins[i].command)
    {
        if (_strcmp(build->args[0], get_Built_Ins[i].command) == 0)
        {
            get_Built_Ins[i].func(build);
            freeArgsAndBuffer(build);
            return (true);
        }
        i++;
    }
    return (false);
}

/**
* exitFunc - this exits the application
* @build: the input build
* Return: returns 1 on success, 0 on failure
*/
int exitFunc(config *build)
{
    register int argCount, exitStatus;

    argCount = countArgs(build->args);
    if (argCount == 1)
    {
        freeMembers(build);
        if (build->errorStatus)
            exit(build->errorStatus);
        exit(EXIT_SUCCESS);
    }
    else if (argCount > 1)
    {
        exitStatus = _atoi(build->args[1]);
        if (exitStatus == -1)
        {
            errno = EILLEGAL;
            build->errorStatus = 2;
            errorHandler(build);
            return (0);
        }
        freeMembers(build);
        exit(exitStatus);
    }
    return (1);
}

/**
* historyFunc - this displays command history
* @build: the input build
* Return: returns 1 on success, 0 on failure
*/
int historyFunc(config *build)
{
    char *str = "Currently in development\n";

    (void)build;
    write(STDOUT_FILENO, str, _strlen(str));
    return (1);
}

/**
* aliasFunc - this displays local aliases
* @build: the input build
* Return: returns 1 on success, 0 on failure
*/
int aliasFunc(config *build)
{
    char *str = "Currently in development\n";

    (void)build;
    write(STDOUT_FILENO, str, _strlen(str));
    return (1);
}
