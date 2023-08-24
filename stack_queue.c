#include "monty.h"

/**
 * opcode_stack - switching mode to stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue = 0;
}

/**
 * opcode_queue - switching mode to queue
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue = 1;
}
