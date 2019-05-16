#include "monty.h"

/**
 * main_loop - function iterates through lines of monty bytecode file
 * @stack: main stack data type
 * @coms: array of instruction structs
 *
 */
void main_loop(stack_t **stack, instruction_t coms[])
{
	char *buffer = NULL, *tok;
	size_t buff_s = 0;
	int line_n = 1;

	while (getline(&buffer, &buff_s, main_s->fp) != -1)
	{
		tok = strtok(buffer, " ");
		if (strcmp(buffer, "\n") == 0 || strcmp(tok, "\n") == 0)
		{
			line_n++;
			continue;
		}
		if (strchr(tok, '\n'))
			tok = strtok(tok, "\n");
		if (strcmp(tok, "push") == 0)
		{
			tok = strtok(NULL, " ");
			main_s->push_n = tok;
			push_o(stack, line_n);
			continue;
		}
		if (!execute_command(stack, tok, line_n, coms))
		{
			free(buffer);
			free_stuff(*stack);
			exit(EXIT_FAILURE);
		}
		line_n++;
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	free_stuff(*stack);
}

/**
 * execute_command - function executes commands
 * @s: main stack data type
 * @tok: current command found in buffer
 * @l: line number
 * @t: array of instruction structs
 *
 * Return: 1 if command was found and executed, 0 otherwise
 */
int execute_command(stack_t **s, char *tok, int l, instruction_t t[])
{
	int i;

	for (i = 0; t[i].f; i++)
		if (strcmp(tok, t[i].opcode) == 0)
		{
			t[i].f(s, l);
			return (1);
		}
	dprintf(2, "L%d: unknown instruction %s\n", l, tok);
	return (0);
}


/**
 * free_stuff - function frees variables
 * @stack: stack to free
 *
 */
void free_stuff(stack_t *stack)
{
	fclose(main_s->fp);
	free_dlistint(stack);
	free(main_s);
}
