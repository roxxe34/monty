#include "monty.h"

void opcode_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    stack_t *top2= top->next;
    stack_t *curr = top2;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = top;
    top->next = NULL;
    top->prev = curr;
    *stack = top2;
    top2->prev = NULL;
}