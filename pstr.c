#include "monty.h"

void opcode_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL && current->n > 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    
    putchar('\n');
}