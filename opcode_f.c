#include "monty.h"

void push_o(stack_t **stack, unsigned int line_number)
{
	int n;
	char *num;

	(void)line_number;
	num = strtok(main_s->opcode_g, " ");
	num = strtok(NULL, " ");
	if (!num || !isdigit(num[0]))
	{
		free_stuff(*stack);
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(num);
	add_dnodeint(stack, n);
}

void pall_o(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}

void pint_o(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%d can't pint, stack empty\n", line_number);
		free_stuff(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop_o(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_stuff(*stack);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_head(stack);
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
