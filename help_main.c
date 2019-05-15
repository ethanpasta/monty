#include "monty.h"

void main_loop(stack_t **stack, instruction_t coms[])
{
        char *buffer = NULL;
	size_t buff_s = 0;
	int i, line_n = 1;

	while (getline(&buffer, &buff_s, main_s->fp) != -1)
	{
		i = 0;
		while (buffer[i] == ' ')
			i++;
		if (buffer[i] == '\n')
		{
			line_n++;
			continue;
		}
		main_s->opcode_g = buffer + i;
		for (i = 0; main_s->opcode_g && coms[i].f; i++)
		{
			if (strncmp(main_s->opcode_g, coms[i].opcode, strlen(coms[i].opcode)) == 0)
			{
				coms[i].f(stack, line_n);
				break;
			}
		}
		if (coms[i].f == NULL)
		{
			free(buffer);
			free_dlistint(*stack);
			invalid_code(line_n, main_s->opcode_g);
		}
		line_n++;
		free(buffer);
		buffer = NULL;
	}
	free_dlistint(*stack);
	free(buffer);
	fclose(main_s->fp);
	free(main_s);
}

void free_stuff(stack_t *stack)
{
	fclose(main_s->fp);
	free_dlistint(stack);
	if (main_s->opcode_g)
		free(main_s->opcode_g);
	free(main_s);
}
