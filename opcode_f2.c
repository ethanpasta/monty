#include "monty.h"

/**
 * add_o - function implements the 'add' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void add_o(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(*stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	delete_dnodeint_head(stack);
}

/**
 * nop_o - function implements the 'nop' opcode (does nothing)
 * @stack: head of stack
 * @line_number: current line number in file
 */
void nop_o(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_o - function implements the 'sub' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void sub_o(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(*stack) < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	delete_dnodeint_head(stack);
}
