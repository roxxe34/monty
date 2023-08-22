#include "monty.h"

instruction_t instructions[] = {
    {"push", opcode_push},
    {"pall", opcode_pall},
    {"pint", opcode_pint},
    {"pop", opcode_pop},
    {"swap", opcode_swap},
    {"add", opcode_add},
    {"nop", opcode_nop},
    {"sub", opcode_sub},
    {"div", opcode_div},
    {"mul", opcode_mul},
    {"mod", opcode_mod},
    
    /* Add more instructions as needed */
    {NULL, NULL}
};

void opcode_push(stack_t **stack, unsigned int line_number)
{
    char *argument = strtok(NULL, " \n\t\a\b$");
    int value;

    if (!argument)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);

    /* Check for atoi conversion error */
    if (value == 0 && strcmp(argument, "0") != 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push(stack, value);
}

void opcode_pall(stack_t **stack, unsigned int line_number)
{
    pall(stack, line_number);
}
void opcode_pint(stack_t **stack, unsigned int line_number)
{
    if (is_empty(*stack))
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    pint(stack, line_number);
}
void opcode_pop(stack_t **stack, unsigned int line_number)
{
    if (is_empty(*stack))
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    pop(stack, line_number);
}
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
void opcode_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
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
void opcode_mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;
    second->n *= first->n;

    pop(stack, line_number);
}
void opcode_mod(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;
    if (first->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    second->n %= first->n;

    pop(stack, line_number);
}