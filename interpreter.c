#include "monty.h"


void run_interpreter(FILE *file)
{
    stack_t *stack = NULL; 

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    char *opcode;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        
        /* Tokenize the line to extract the opcode and argument */
        opcode = strtok(line, " \n\t\a\b$");

        if (opcode)
        {
            /* Lookup and execute the opcode function using opcode-to-function mapping */
            int i = 0;
            while (instructions[i].opcode)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
            if (!instructions[i].opcode)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    
    /* Free memory */
    free(line);
}