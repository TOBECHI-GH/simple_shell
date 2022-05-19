#include "holberton.h"

/**
* cdFunc - executes the cd builtin
* @build: input build
* Return: returns 1 on success, 0 on failure
*/
int cdFunc(config *build)
{
    register uint count = 0;
    _Bool ableTo_Change = false;

    count = countArgs(build->args);
    if (count == 1)
        ableTo_Change = cdToHome(build);
    else if (count == 2 && _strcmp(build->args[1], "-") == 0)
        ableTo_Change = cdToPrevious(build);
    else
        ableTo_Change = cdToCustom(build);
    if (ableTo_Change)
        updateEnviron(build);
    return (1);
}

/**
* cdToHome - changes directory to home
* @build: returns input build
* Return: returns true on success, false on failure
*/
_Bool cdToHome(config *build)
{
    register int i;
    char *str_, *ptr_;

    i = searchNode(build->env, "HOME");
    if (i == -1)
    {
        return (true);
    }
    str_ = getNodeAtIndex(build->env, i);
    ptr_ = _strchr(str, '=');
    ptr_++;
    chdir(ptr_);
    free(str_);
    return (true);
}

/**
* cdToPrevious - change directory to previous directory -
* address is found in OLDPWD env var
* @build: input build
* Return: true on success, false on failure
*/
_Bool cdToPrevious(config *build)
{
    register int i;
    char *str, *ptr;
    char *current = NULL;

    current = getcwd(current, 0);
    i = searchNode(build->env, "OLDPWD");
    if (i == -1)
    {
        chdir(current);
        write(STDOUT_FILENO, current, _strlen(current));
        displayNewLine();
        return (true);
    }
    str = getNodeAtIndex(build->env, i);
    ptr = _strchr(str, '=');
    ptr++;
    chdir(ptr);
    write(STDOUT_FILENO, ptr, _strlen(ptr));
    displayNewLine();
    free(str);
    return (true);
}

/**
* cdToCustom - changes directory to what user inputs in
* @build: gives the input build
* Return: returns true on success, false on failure
*/
_Bool cdToCustom(config *build)
{
    register int change_Status;

    change_Status = chdir(build->args[1]);
    if (change_Status == -1)
    {
        errno = EBADCD;
        errorHandler(build);
        return (false);
    }
    return (true);
}

/**
* updateEnviron - changes environmental variables
* @build: input build
* Return: returns true on success false on failure
*/
_Bool updateEnviron(config *build)
{
    register int i;

    i = updateOld(build);
    updateCur(build, i);
    return (true);
}
