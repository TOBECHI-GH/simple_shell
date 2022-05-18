#include "holberton.h"

/**
 * updateOld - this updates OLDPWD to current PWD
 * @build: gives the input build
 * Return: Returns the index in linked list of PWD on success -
 * If PWD or OLDPWD does not exist in environ vars,
 * return -1
 */
int updateOld(config *build)
{
	register int pwd_Index = 0, index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	pwd_Index = searchNode(build->env, "PWD");
	if (pwd_Index == -1)
	{
		return (-1);
	}
	current = getNodeAtIndex(build->env, pwd_Index);
	_strcat(old, current);
	insertNullByte(old, _strlen(current) + 4);
	free(current);
	index = searchNode(build->env, "OLDPWD");
	if (index == -1)
	{
		return (-1);
	}
	deleteNodeAtIndex(&build->env, index);
	addNodeAtIndex(&build->env, index, old);
	insertNullByte(old, 0);
	return (pwd_Index);
}

/**
 * updateCur - this updates PWD to accurately reflect current directory
 * @build: this gives the input build
 * @index: this index in linked list of where to insert PWD env var
 * Return: returns true on success, false on failure
 */
_Bool updateCur(config *build, int index)
{
	static char tmp_[BUFSIZE], cwd_[BUFSIZE];

	getcwd(tmp_, BUFSIZE);
	_strcat(cwd_, "PWD=");
	_strcat(cwd_, tmp_);
	if (index > -1)
	{
		deleteNodeAtIndex(&build->env, index);
		addNodeAtIndex(&build->env, index, cwd_);
	} else
		addNodeAtIndex(&build->env, 0, cwd_);
	insertNullByte(tmp_, 0);
	insertNullByte(cwd_, 0);
	return (true);
}