#include "monty.h"

void opcode_add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;
    second->n += first->n;
    pop(stack, line_number);
}

void free_stack(stack_t *stack)
{
    stack_t *current;
    stack_t *next;
    if (stack == NULL)
        return;

    current = stack;
    next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    stack = NULL;
}