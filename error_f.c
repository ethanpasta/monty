#include "monty.h"

void file_err(char *file)
{
	if (!file)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

void malloc_fail()
{
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void push_no_arg(unsigned int line_n)
{
	printf("L%u: usage: push integer\n", line_n);
	exit(EXIT_FAILURE);
}

void invalid_code(unsigned int line_n, char *opcode)
{
	printf("L%u: unknown instruction %s\n", line_n, opcode);
	exit(EXIT_FAILURE);
}
