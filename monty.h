#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct help_s - helper struct to use with one external variable
 * @fp: file descriptor
 * @push_n: value to push
 * @buff: buffer for getline
 * @stack_s: pointer to local stack
 */
typedef struct help_s
{
	FILE *fp;
	char *push_n;
	char *buff;
	stack_t *stack_s;
} help_t;

typedef stack_t dlistint_t;
extern help_t *main_s;

void file_err(char *);
void malloc_fail(void);
void push_o(stack_t **, unsigned int);
int isnum(char *);
void pall_o(stack_t **, unsigned int);
void pint_o(stack_t **, unsigned int);
void pop_o(stack_t **, unsigned int);
void swap_o(stack_t **, unsigned int);
void add_o(stack_t **, unsigned int);
void nop_o(stack_t **, unsigned int);
void sub_o(stack_t **, unsigned int);
void div_o(stack_t **, unsigned int);
void mul_o(stack_t **, unsigned int);
void mod_o(stack_t **, unsigned int);
void pstr_o(stack_t **, unsigned int);
void rotl_o(stack_t **, unsigned int);

void main_loop(instruction_t *);
void free_stuff(void);
int execute_command(char *, int, instruction_t []);

size_t print_dlistint(const dlistint_t *h);
void free_dlistint(dlistint_t *head);
int delete_dnodeint_head(dlistint_t **head);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
size_t dlistint_len(const dlistint_t *h);

#endif /* MONTY_H */
