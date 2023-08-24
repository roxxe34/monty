#include "monty.h"
global_var global;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readf(av[1], &stack);
	free_stack(stack);
	return (0);
}
