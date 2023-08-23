#include "monty.h"

void opcode_pall(stack_t **stack, unsigned int line_number)
{
    pall(stack, line_number);
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}