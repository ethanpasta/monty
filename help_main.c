#include "monty.h"

char *opcode_g = NULL;

void main_loop(stack_t **stack, FILE *fp, instruction_t coms[])
{
        char *buffer = malloc(sizeof(char) * 32);
	size_t buff_s = 32;
	int i, line_n = 1;

	while (getline(&buffer, &buff_s, fp) != -1)
	{
		i = 0;
		while (buffer[i] == ' ')
			i++;
		if (buffer[i] == '\n')
			continue;
		opcode_g = strdup(buffer + i);
		free(buffer);
		buffer = NULL;
		for (i = 0; opcode_g && coms[i].f; i++)
		{
			if (strncmp(opcode_g, coms[i].opcode, 4) == 0)
			{
				coms[i].f(stack, line_n);
				break;
			}
		}
		if (coms[i].f == NULL)
			invalid_code(line_n, opcode_g);
		free(opcode_g);
		opcode_g = NULL;
		line_n++;
	}
	free(buffer);
	free_stack(*stack);
}
