#include "monty.h"
/**
 * opcode_swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int tmp;

	first = *stack;
	if (first == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = first->n;
	first->n = first->next->n;
	first->next->n = tmp;
}

/**
 * opcode_add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	opcode_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * opcode_nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void opcode_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * opcode_pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
