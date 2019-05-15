#include "monty.h"

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
	FILE *fp;

	if (ac != 2)
		file_err(NULL);
	fp = fopen(av[1], "r");
	if (!fp)
		file_err(av[1]);
	main_loop(&stack, fp, coms);
	fclose(fp);
	return 1;
}
