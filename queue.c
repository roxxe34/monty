#include "monty.h"

void opcode_queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    is_stack_mode = false;
}

int is_empty(stack_t *stack)
{
    return stack == NULL;
}