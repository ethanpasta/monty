#include "monty.h"

void file_err(char *file)
{
	if (!file)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("Error: Can't open file %s\n", file);
	free(main_s);
	exit(EXIT_FAILURE);
}

void malloc_fail()
{
	printf("Error: malloc failed\n");

	exit(EXIT_FAILURE);
}

void invalid_code(unsigned int line_n, char *opcode)
{
	printf("L%u: unknown instruction %s", line_n, opcode);
	free(main_s->opcode_g);
	fclose(main_s->fp);
	free(main_s);
	exit(EXIT_FAILURE);
}
