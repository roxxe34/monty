#include "monty.h"

void opcode_swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->next = first;
    second->prev = NULL;
    first->prev = second;

    *stack = second;
}