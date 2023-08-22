#include "monty.h"

void push(stack_t **stack, int value)
{
    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
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

int is_empty(stack_t *stack)
{
    return stack == NULL;
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
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;
    
    printf("%d\n", temp->n);   
}

void free_stack(stack_t *stack)
{
    stack_t *current;
    stack_t *next;
    /* Check if the stack is not NULL */
    if (stack == NULL)
        return;

    /* Use a loop or recursion to free each element */
    current = stack;
    next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* Set the stack pointer to NULL */
    stack = NULL;
}
size_t stack_size(stack_t *stack)
{
    int len = 0;
    while (stack != NULL)
    {
        len++;
        stack = stack->next;
    }
    return len;
    
}
