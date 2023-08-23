#include "monty.h"
/**
 * opcode_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
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

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    if (is_stack_mode)
    {
        new_node->next = *stack;
        if (*stack)
            (*stack)->prev = new_node;
        *stack = new_node;
    }
    else
    {
        stack_t *temp = *stack;
        if (!temp)
        {
            new_node->next = NULL;
            *stack = new_node;
        }
        else
        {
            while (temp->next)
                temp = temp->next;
            temp->next = new_node;
            new_node->next = NULL;
            new_node->prev = temp;
        }
    }
}