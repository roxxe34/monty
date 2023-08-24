#include "monty.h"

/**
 * opcode_pstr - Prints a string of characters.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
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
 * opcode_rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
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
 * opcode_rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
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
