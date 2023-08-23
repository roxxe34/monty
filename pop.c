#include "monty.h"

void opcode_pop(stack_t **stack, unsigned int line_number)
{
    if (is_empty(*stack))
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    pop(stack, line_number);
}

int pop(stack_t **stack, unsigned int line_number)
{
    int value;
    stack_t *temp;

    (void)line_number;

    if (!*stack)
    {
        fprintf(stderr, "Error: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }

    value = (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
    return value;
}
