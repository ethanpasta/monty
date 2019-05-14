#include "monty.h"

int push(stack_t **s, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (0);
	new->n = n;
	new->next = *s;
	new->prev = NULL;
	return (1);
}

int pop(stack_t **s)
{
	stack_t *tmp;

	if (!*s)
		return (0);
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	(*s)->prev = NULL;
	return (1);
}

int print_top(stack_t *s)
{
	if (!s)
		return (0);
	printf("%d\n", s->n);
	return (1);
}

void print_stack(stack_t *s)
{
	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
