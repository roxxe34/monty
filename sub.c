#include "monty.h"

void opcode_sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;
    second->n -= first->n;
    pop(stack, line_number);
}