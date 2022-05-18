#include "holberton.h"

/**
 * freeMembers - this frees build config members
 * @build: input build
 */
void freeMembers(config *build)
{
	if (build->env)
		freeList(build->env);
	if (build->args)
		freeArgs(build->args);
	if (build->buffer)
		free(build->buffer);
}

/**
 * freeArgsAndBuffer - frees args and buffer
 * @build: input build
 */
void freeArgsAndBuffer(config *build)
{
	freeArgs(build->args);
	free(build->buffer);
}

/**
 * freeList - this frees a linked list
 * @head: the double pointer to head of list
 */
void freeList(linked_l *head)
{
	linked_l *current_;
	linked_l *tmp_;

	if (!head)
		return;
	current_ = head;
	while (current_)
	{
		tmp_ = current_;
		current_ = tmp_->next;
		free(tmp_->string);
		free(tmp_);
	}
	head = NULL;
}

/**
 * freeArgs - this is the helper func that frees double pointer arg
 * @args: the array of char pointers
 */
void freeArgs(char **args)
{
	register uint i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
}
