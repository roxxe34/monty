#include "monty.h"

void opcode_div(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;
    if (second->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    second->n /= first->n;

    pop(stack, line_number);
}