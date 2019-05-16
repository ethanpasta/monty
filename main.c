#include "monty.h"

help_t *main_s = NULL;

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: exit status
 */
int main(int ac, char **av)
{
	instruction_t coms[] = {
		{"push", push_o},
		{"pall", pall_o},
		{"pint", pint_o},
		{"pop", pop_o},
		{"swap", swap_o},
		{NULL, NULL}
	};
	stack_t *stack = NULL;

	if (ac != 2)
		file_err(NULL);
	main_s = malloc(sizeof(help_t));
	if (!main_s)
		malloc_fail(stack);
	main_s->fp = fopen(av[1], "r");
	if (!main_s->fp)
		file_err(av[1]);
	main_s->push_n = NULL;
	main_loop(&stack, coms);
	return (0);
}
