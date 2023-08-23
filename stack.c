#include "monty.h"

void opcode_stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    is_stack_mode = true;
}

size_t stack_size(stack_t *stack)
{
    int len = 0;
    while (stack != NULL)
    {
        len++;
        stack = stack->next;
    }
    return len;
    
}
