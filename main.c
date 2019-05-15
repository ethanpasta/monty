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
		{"add", add_o},
		{"nop", nop_o},
		{NULL, NULL}
	};
	stack_t *stack = NULL;
	if (ac != 2)
		file_err(NULL);
	main_s = malloc(sizeof(help_t));
	if (!main_s)
		return (0);
	main_s->fp = fopen(av[1], "r");
	if (!main_s->fp)
		file_err(av[1]);
	main_loop(&stack, coms);
	return 1;
}
