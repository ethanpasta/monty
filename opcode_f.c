#include "monty.h"

/**
 * push_o - function pushes node onto stack
 * @stack: head of stack
 * @line_number: current line number in file
 */
void push_o(stack_t **stack, unsigned int line_number)
{
	int n;
	char *num = main_s->push_n;

	if (!num || !isdigit(num[0]))
	{
		free_stuff(*stack);
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(num);
	add_dnodeint(stack, n);
}

/**
 * pall_o - function prints stack
 * @stack: head of stack
 * @line_number: current line number in file
 */
void pall_o(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}

/**
 * pint_o - function prints value at head of stack
 * @stack: head of stack
 * @line_number: current line number in file
 */
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

/**
 * pop_o - function removes node from top of stack
 * @stack: head of stack
 * @line_number: current line number in file
 */
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

/**
 * swap_o - function swaps values of two top nodes on stack
 * @stack: head of stack
 * @line_number: current line number in file
 */
void swap_o(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_stuff(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
