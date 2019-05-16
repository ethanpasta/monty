#include "monty.h"

/**
 * file_err - function takes care of error that occurs with the file
 * @file: name of the file inputed
 *
 */
void file_err(char *file)
{
	if (!file)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	dprintf(2, "Error: Can't open file %s\n", file);
	free(main_s);
	exit(EXIT_FAILURE);
}

/**
 * malloc_fail - function takes care of error that occurs with malloc
 * @h: stack data type
 *
 */
void malloc_fail(stack_t *h)
{
	dprintf(2, "Error: malloc failed\n");
	free_stuff(h);
	exit(EXIT_FAILURE);
}
