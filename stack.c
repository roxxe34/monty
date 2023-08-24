#include "monty.h"
/**
 * opcode_push - Pushes an element to the stack or queue.
 * @stack: Double pointer to the top of the stack or queue.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;
	if (global.queue == 0)
	{
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
	}else
	{
		top = malloc(sizeof(stack_t));
		if (top == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		top->n = global.push_arg;
		top->next = NULL;

		if (*stack == NULL)
		{
			top->prev = NULL;
			*stack = top;
		}
		else
		{
			stack_t *last = *stack;
			while (last->next != NULL)
				last = last->next;
			last->next = top;
			top->prev = last;
		}
	}
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
 * opcode_pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
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
 * opcode_pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: None.
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
