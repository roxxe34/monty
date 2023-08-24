#include "monty.h"
/**
 * opcode_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	second->n += first->n;
	pop(stack, line_number);
}
/**
 * opcode_sub - Subtracts the top element from the second
 * top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	second->n -= first->n;
	pop(stack, line_number);
}
/**
 * opcode_div - Divides the second top element by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (second->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	second->n /= first->n;

	pop(stack, line_number);
}
/**
 * opcode_mul - Multiplies the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n *= first->n;

	pop(stack, line_number);
}
/**
 * opcode_mod - Computes the modulus of the second top element
 * by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	second->n %= first->n;

	pop(stack, line_number);
}
