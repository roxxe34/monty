#include "monty.h"
/**
 * opcode_nop - it do nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * opcode_pstr - Prints a string of characters.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
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
	stack_t *top = *stack;
	stack_t *top2 = top->next;
	stack_t *curr = top2;
	(void)line_number;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = top;
	top->next = NULL;
	top->prev = curr;
	*stack = top2;
	top2->prev = NULL;
}
/**
 * opcode_rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *second_to_last = NULL;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}

	last->next = *stack;
	(*stack)->prev = last;
	second_to_last->next = NULL;
	last->prev = NULL;

	*stack = last;
}
/**
 * is_empty - Checks if a stack is empty.
 * @stack: Pointer to the top of the stack.
 *
 * Return: 1 if the stack is empty, 0 otherwise.
 */
int is_empty(stack_t *stack)
{
	return (stack == NULL);
}
