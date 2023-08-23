#include "monty.h"

void opcode_pint(stack_t **stack, unsigned int line_number)
{
    if (is_empty(*stack))
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    pint(stack, line_number);
}

void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;
    
    printf("%d\n", temp->n);   
}