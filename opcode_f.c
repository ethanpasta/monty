#include "monty.h"

void push_o(stack_t **stack, unsigned int line_number)
{
	int n;
	char *num;

	(void)line_number;
	num = strtok(opcode_g, " ");
	num = strtok(NULL, " ");
	if (!num || !isdigit(num[0]))
		push_no_arg(line_number);
	n = atoi(num);
	push(stack, n);
}

void pall_o(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	print_stack(*stack);
}

void pint_o(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

void pop_o(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

void swap_o(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

void add_o(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

void nop_o(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}
