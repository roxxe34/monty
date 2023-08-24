#include "monty.h"
/**
 * opcode_push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \n\t\a\b$");
	int value;

	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	/* Check for atoi conversion error */
	if (value == 0 && strcmp(argument, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push(stack, value);
}
/**
 * opcode_pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	pint(stack, line_number);
}
/**
 * opcode_pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
}
/**
 * opcode_swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->next = first;
	second->prev = NULL;
	first->prev = second;

	*stack = second;
}
/**
 * opcode_pchar - Prints the ASCII character at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;

	if (first->n > 127 || first->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(first);
		exit(EXIT_FAILURE);
	}

	putchar(first->n);
	putchar('\n');
	pop(stack, line_number);
}
