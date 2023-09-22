#include "monty.h"
/**
 * main - the driver function
 * @argc: The argument count to main
 * @argv: An array of string commandline arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t n_read = 0;
	stack_t *stack = NULL;
	int line_number;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while ((getline(&input, &n_read, file) != -1))
	{
		search_execute(input, &stack, line_number);
		line_number++;
		if (flag.err_flag == 1)
			break;
		else if (flag.err_flag == -1)
			continue;
	}
	if (flag.err_flag)
	{
		cleanup(file, input, stack);
		exit(EXIT_FAILURE);
	}
	cleanup(file, input, stack);
	return (0);
}
/**
 * cleanup - frees memory
 * @file: A file pointer
 * @input: An array of user input
 * @stack: The stack
 *
 * Return: Nothing.
 */
void cleanup(FILE *file, char *input, stack_t *stack)
{
	fclose(file);
	free(input);
	free_stack(stack);
}

