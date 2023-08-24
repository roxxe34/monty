#include "monty.h"
/**
 * main - Entry point of Monty interpreter.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 *
 * This function processes Monty bytecode instructions from a file specified as
 * a command-line argument. It opens the file, interprets its content, and exit
 * with the appropriate status code.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	run_interpreter(file);

	fclose(file);
	return (0);
}
