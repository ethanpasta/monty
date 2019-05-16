#include "monty.h"

/**
 * pchar_o - function implements the 'pchar' opcode
 * @stack: head of stack
 * @line_number: current line number in the file
 */
void pchar_o(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
