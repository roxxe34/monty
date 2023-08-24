#include "monty.h"
/**
 * opcode_push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * opcode_pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	curr = *stack;
	(void)line_number;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * opcode_pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	curr = *stack;
	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", curr->n);
}

/**
 * opcode_pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * free_stack - free a list
 * @head: pointer to first node
 *
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
