#include "monty.h"

void opcode_pchar(stack_t **stack, unsigned int line_number)
{
    if (is_empty(*stack))
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    stack_t *first = *stack;
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