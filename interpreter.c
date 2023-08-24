#include "monty.h"
static instruction_t instructions[] = {
	{"push", opcode_push},
	{"pall", pall},
	{"pint", opcode_pint},
	{"pop", opcode_pop},
	{"swap", opcode_swap},
	{"add", opcode_add},
	{"nop", opcode_nop},
	{"sub", opcode_sub},
	{"div", opcode_div},
	{"mul", opcode_mul},
	{"mod", opcode_mod},
	{"pchar", opcode_pchar},
	{"pstr", opcode_pstr},
	{"rotl", opcode_rotl},
	{"rotr", opcode_rotr},
	{NULL, NULL}
};
/**
 * process_line - Process a code line and execute matching instruction.
 * @line: Code line to process.
 * @stack: Pointer to interpreter stack.
 * @line_number: Line number in the code.
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(line, " \n\t\a\b$");

	if (opcode)
	{
		int i = 0;

		while (instructions[i].opcode)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				break;
			}
			i++;
		}
		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * run_interpreter - Execute interpreter on input file.
 * @file: Input file to interpret.
 */
void run_interpreter(FILE *file)
{
	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line[0] == '#' || line[0] == '\n')
		{
			continue;
		}

		process_line(line, &stack, line_number);
	}
	free(line);
}
