#include "monty.h"

/**
 * search_execute - searches for the opcode function and calls it
 * @input: The opcode function specified by the user
 * @stack: The stack
 * @line_number: The line number in the file
 *
 * Return: 1 in case of error, Otherwise return 0
 */
int search_execute(char *input, stack_t **stack, int line_number)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char operation[40];
	int i;
	int result, ret;

	result = sscanf(input, "%s%i", operation, &global_n);
	if (result == -1)
		return (-1);
	ret = strcmp("pall", operation);
	if (result != 2 && ret != 0)
	{
		fprintf(stderr, "L<%i>: usage: push integer\n", line_number);
		return (1);
	}
	i = 0;
	while (functions[i].opcode != NULL)
	{
		if ((strcmp(functions[i].opcode, operation) == 0))
		{
			break;
		}
		i++;
	}
	if (functions[i].opcode == NULL)
	{
		fprintf(stderr, "L<%i>: unknown instruction<%s>\n", line_number, operation);
		return (1);
	}
	functions[i].f(stack, line_number);
	return (0);
}
/**
 * free_stack - frees the stack
 * @stack: The stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

