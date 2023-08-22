#include "monty.h"

instruction_t instructions[] = {
    {"push", opcode_push},
    {"pall", opcode_pall},
    {"pint", opcode_pint},
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
    pint(stack, line_number);
}