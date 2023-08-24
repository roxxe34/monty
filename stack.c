#include "monty.h"
/**
 * push - Adds a new node at the beginning of a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @value: The value to be added to the stack.
 *
 * Return: None.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * pop - Removes the top element of a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: The value of the removed element.
 */
int pop(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp;

	(void)line_number;


	if (!*stack)
	{
		fprintf(stderr, "Error: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
	return (value);
}
/**
 * pall - Prints all elements of a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: None.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (is_empty(*stack))
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - Prints the top element of a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: None.
 */
void pint(stack_t **stack, unsigned int line_number)
{


	printf("%d\n", (*stack)->next->n);
}
/**
 * free_stack - Frees all elements of a stack.
 * @stack: A pointer to the top of the stack.
 *
 * Return: None.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;
	stack_t *next;

	if (stack == NULL)
		return;

	current = stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	stack = NULL;
}
