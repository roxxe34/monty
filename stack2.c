#include "monty.h"

/**
 * opcode_pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int chr = 0;

	(void)line_number;


	while (tmp)
	{
		chr = tmp->n;
		if (chr == 0 || _isalpha(chr) == 0)
			break;
		putchar(chr);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * opcode_rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;


	int data = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	data = curr->n;

	while (curr->next)
	{
		curr = curr->next;
		curr->prev->n = curr->n;
	}

	curr->n = data;
}

/**
 * opcode_rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	int data = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (curr->next)
		curr = curr->next;

	data = curr->n;

	while (curr->prev)
	{
		curr = curr->prev;
		curr->next->n = curr->n;
	}

	curr->n = data;
}
